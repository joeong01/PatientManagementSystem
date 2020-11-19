#include "PatientManagementModule.h"


PatientManagementModule::PatientManagementModule(List* pl, List* gl)
    :patientList(pl),guardianList(gl)
{}

void PatientManagementModule::printPatientTable()
{
    Patient* ptr = nullptr;
    std::string line(50, '-');

    printf("%-10s|%-20s|%-20s\n", "Index", "Patient Name", "Patient Address");
    std::cout << line << std::endl;

    ptr = dynamic_cast<Patient*>(patientList->getHead());
    int index = 1;
    //use while loop to display until end of patientList
    while (ptr != nullptr)
    {
        printf("%-10d|", index);
        ptr->print();
        ptr = dynamic_cast<Patient*>(ptr->getNext());
        ++index;
    }

    std::cout << line << std::endl;
}

void PatientManagementModule::printGuardianTable()
{
    Guardian* ptr = nullptr;
    std::string line(50, '-');

    printf("%-10s|%-20s|%-20s\n", "Index", "Guardian Name", "Guardian Address");
    std::cout << line << std::endl;

    ptr = dynamic_cast<Guardian*>(guardianList->getHead());
    int index = 1;
    //use while loop to display until end of guardianList
    while (ptr != nullptr)
    {
        printf("%-10d|", index);
        ptr->print();
        ptr = dynamic_cast<Guardian*>(ptr->getNext());
        ++index;
    }

    std::cout << line << std::endl;
}

void PatientManagementModule::addPatient()
{
    int id(0), age(0);
    string name(""), address(""), contact(""), illness("");
    bool insurance("");
    int doctor_Id(0);
    Medicine* medicine = new Medicine (0,"",0);

    id = InputModule::getIntegerInput("Enter Patient ID: ");
    name = InputModule::getStringInput("Enter Patient Name: ");
    age = InputModule::getIntegerInput("Enter Patient Age: ");
    address = InputModule::getStringInput("Enter Patient Address: ");
    contact = InputModule::getStringInput("Enter Patient Contact: ");
    illness = InputModule::getStringInput("Enter Patient Illness: ");
    insurance = InputModule::getCharInput("Patient has Insurance (Y/N): ");
    doctor_Id = InputModule::getIntegerInput("Enter Patient's Doctor ID: ");
    medicine->setId(InputModule::getIntegerInput("Enter Medicine ID: "));
    Node* patient = new Patient(id, age, name, address, contact, illness, insurance, doctor_Id, medicine);
    patientList->add(patient);
}

void PatientManagementModule::modifyPatient()
{
    int input = 0;
    printPatientTable();
    input = InputModule::getIntegerInput("Enter Patient ID:");
    cout << string(50, '-') << endl;
    if (input > 0) {
        Node* target = searchPatient(patientList);
        Patient* p = dynamic_cast<Patient*>(target);
        int option = 0;
        bool valid = true;
        do {
            cout << "---------------Edit Medicine Records--------------" << endl;
            cout << "1) ID" << endl;
            cout << "2) Name" << endl;
            cout << "3) Age" << endl;
            cout << "4) Address" << endl;
            cout << "5) Contact" << endl;
            cout << "6) Insurance" << endl;
            cout << "7) Doctor ID" << endl;
            cout << "8) Medicine List" << endl;
            cout << "9) Exit\n" << endl;
            option = InputModule::getIntegerInput("Enter option: ");
            switch (option) {
            case 1:
                p->setId(InputModule::getIntegerInput("Enter Patient ID: "));
                break;
            case 2:
                p->setName(InputModule::getStringInput("Enter Patient Name: "));
                break;
            case 3:
                p->setAge(InputModule::getIntegerInput("Enter Patient Age: "));
                break;
            case 4:
                p->setAddress(InputModule::getStringInput("Enter Patient Address: "));
                break;
            case 5:
                p->setContact(InputModule::getStringInput("Enter Patient Contact: "));
                break;
            case 6:
                p->setInsurance(InputModule::getCharInput("Patient has Insurance (Y/N): "));
                break;
            case 7:
                p->setDoctorName(InputModule::getStringInput("Enter Patient's Doctor Name: "));
                break;
            case 8:
                Medicine* m = dynamic_cast<Medicine*>(target);
                m->setId(InputModule::getIntegerInput("Enter Medicine ID: "));
                p->setMedicine(m);
                break;
            case 9:
                valid = false;
                break;
            default:
                cout << "Option Invalid!" << endl;
                break;
            }
        } while (valid);
        
    } else cout << "Selection not found!" << endl;
}

void PatientManagementModule::removePatient()
{
    cout << "---------------Delete Patient--------------" << endl;
    Node* select = searchPatient(patientList);
    if (select != NULL) {
        if (select == patientList->getHead()) {
            Node* next = select->getNext();
            next->setPrev(NULL);
            patientList->setHead(next);
        }
        else if (select == patientList->getTail()) {
            Node* prev = select->getPrev();
            prev->setNext(NULL);
            patientList->setTail(prev);
        }
        else {
            Node* prev = select->getPrev();
            Node* next = select->getNext();
            next->setPrev(prev);
            prev->setNext(next);
        }
        delete select;
        cout << "Deletion Success!" << endl;
    }
    else cout << "Selection not found!" << endl;
}

void PatientManagementModule::displayPatient()
{
    if (patientList == NULL) cout << "Empty Record!" << endl;
    else {
        Node* ptr = patientList->getHead();
        cout << "\n<------------List of Patient Records------------>\n";
        while (ptr != nullptr) {
            Patient* p = dynamic_cast<Patient*>(ptr);
            cout << "Patient ID: " << p->getId() << endl;
            cout << "Patient Name: " << p->getName() << endl;
            cout << "Patient Age: " << p->getAge() << endl;
            cout << "Patient Address: " << p->getAddress() << endl;
            cout << "Patient Contant: " << p->getContact() << endl;
            cout << "Patient Insurance: " << p->getInsurance() << endl;
            cout << "Doctor ID: " << p->getDoctorId() << endl;
            cout << "Medicine List: " << p->getMedicineList() << endl;

            ptr = ptr->getNext();
        }
    }
}

void PatientManagementModule::modifyGuardian()
{
    int input = 0;
    printGuardianTable();
    input = InputModule::getIntegerInput("Enter Guardian ID:");
    cout << string(50, '-') << endl;
    if (input > 0) {
        Node* target = searchGuardian(guardianList);
        Guardian* g = dynamic_cast<Guardian*>(target);
        int option = 0;
        bool valid = true;
        do{
            cout << "---------------Edit Patient Records--------------" << endl;
            cout << "1) ID" << endl;
            cout << "2) Name" << endl;
            cout << "3) Gender" << endl;
            cout << "4) Age" << endl;
            cout << "5) Address" << endl;
            cout << "6) Contact" << endl;
            cout << "7) Exit\n" << endl;
            option = InputModule::getIntegerInput("Enter option: ");
            switch (option) {
            case 1:
                g->setId(InputModule::getIntegerInput("Enter Guardian ID: "));
                break;
            case 2:
                g->setName(InputModule::getStringInput("Enter Guardian Name: "));
                break;
            case 3:
                g->setGender(InputModule::getCharInput("Enter Guardian Gender: "));
                break;
            case 4:
                g->setAge(InputModule::getIntegerInput("Enter Guardian Age: "));
                break;
            case 5:
                g->setAddress(InputModule::getStringInput("Enter Guardian Address: "));
                break;
            case 6:
                g->setContact(InputModule::getStringInput("Enter Guardian Contact: "));
                break;
            case 7:
                valid = false;
                break;
            default:
                cout << "Option Invalid!" << endl;
                break;
            }
        }while (valid);
    }else cout << "Selection not found!" << endl;
}

void PatientManagementModule::removeGuardian()
{
    cout << "---------------Delete Guardian--------------" << endl;
    Node* select = searchGuardian(guardianList);
    if (select != NULL) {
        if (select == guardianList->getHead()) {
            Node* next = select->getNext();
            next->setPrev(NULL);
            guardianList->setHead(next);
        }
        else if (select == guardianList->getTail()) {
            Node* prev = select->getPrev();
            prev->setNext(NULL);
            guardianList->setTail(prev);
        }
        else {
            Node* prev = select->getPrev();
            Node* next = select->getNext();
            next->setPrev(prev);
            prev->setNext(next);
        }
        delete select;
        cout << "Deletion Success!" << endl;
    }
    else cout << "Selection not found!" << endl;
}

void PatientManagementModule::displayGuardian()
{
    if (guardianList == NULL) cout << "Empty Record!" << endl;
    else {
        Node* ptr = guardianList->getHead();
        cout << "\n<------------List of Guardian Records------------>\n";
        while (ptr != nullptr) {
            Guardian* g = dynamic_cast<Guardian*>(ptr);
            cout << "Guardian ID: " << g->getId() << endl;
            cout << "Guardian Name: " << g->getName() << endl;
            cout << "Guardian Gender: " << g->getGender() << endl;
            cout << "Guardian Age: " << g->getAge() << endl;
            cout << "Guardian Address: " << g->getAddress() << endl;
            cout << "Guardian Contant: " << g->getContact() << endl;

            ptr = ptr->getNext();
        }
    }
}
