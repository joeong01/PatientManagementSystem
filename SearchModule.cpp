#include "SearchModule.h"
using namespace std;

SearchModule::SearchModule(List* pl, List* dl, List* ml, List* gl, List* payment)
	:patientList(pl), doctorList(dl), medicineList(ml), guardianList(gl), paymentList(payment)
{}

void SearchModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Welcome to Patient Management System" << endl;
	cout << line << endl;
	cout << "1 -> Search Patient Record" << endl;
	cout << "2 -> Search Guardian Record" << endl;
	cout << "3 -> Search Doctor Record" << endl;
	cout << "4 -> Search Medicine Record" << endl;
	cout << "5 -> Search Payment Record" << endl;
	cout << "6 -> Return to Main Menu" << endl;
	cout << line << endl;
}

void SearchModule::mainProcess(int input) {
	switch (input) {
	case 1:
		searchPatient();
		break;
	case 2:
		searchGuardian();
		break;
	case 3:
		searchDoctor();
		break;
	case 4:
		searchMedicine();
		break;
	case 5:
		searchPayment();
		break;
	case 6:
		std::cout << "Thank you for using the system.\nHope you have a nice day." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid input! Please try again!" << std::endl;
	}
}

//search doctor record
void SearchModule::searchDoctor()
{
	int check = 0;
	bool functionLoop = true;
	do {
		check = InputModule::getIntegerInput("Enter the doctor ID (-1 to exit):");

		if (check == -1) {
			functionLoop = false;
		}
		else {
			//check from the given order ID
			Doctor* n = dynamic_cast<Doctor*>(doctorList->getHead());
			bool found = false;

			while (!found) {
				if (n == nullptr) {
					cout << "Failed to find the doctor record." << endl;
					break;
				}

				if (n->getId() == check) {
					n->printDetail();
					found = true;
				}

				n = dynamic_cast<Doctor*>(n->getNext());
			}
		}
	} while (functionLoop);
	
}


//search patient record
void SearchModule::searchPatient()
{
	int check = 0;
	bool functionLoop = true;
	do {
		check = InputModule::getIntegerInput("Enter the patient ID (-1 to exit):");

		if (check == -1) {
			functionLoop = false;
		}
		else {
			//check from the given order ID
			Patient* n = dynamic_cast<Patient*>(patientList->getHead());
			bool found = false;

			while (!found) {
				if (n == nullptr) {
					cout << "Failed to find the patient record." << endl;
					break;
				}

				if (n->getId() == check) {
					n->printDetail();
					found = true;
				}

				n = dynamic_cast<Patient*>(n->getNext());
			}
		}
	} while (functionLoop);
}


//search for medicine record
void SearchModule::searchMedicine()
{
	int check = 0;
	bool functionLoop = true;
	do {
		check = InputModule::getIntegerInput("Enter the medicine ID (-1 to exit):");

		if (check == -1) {
			functionLoop = false;
		}
		else {
			//check from the given order ID
			Medicine* n = dynamic_cast<Medicine*>(medicineList->getHead());
			bool found = false;

			while (!found) {
				if (n == nullptr) {
					cout << "Failed to find the medicine record." << endl;
					break;
				}

				if (n->getId() == check) {
					n->printDetail();
					found = true;
				}

				n = dynamic_cast<Medicine*>(n->getNext());
			}
		}
	} while (functionLoop);
}


//search for guardian record
void SearchModule::searchGuardian()
{
	int check = 0;
	bool functionLoop = true;
	do {
		check = InputModule::getIntegerInput("Enter the guardian ID (-1 to exit):");

		if (check == -1) {
			functionLoop = false;
		}
		else {
			//check from the given order ID
			Guardian* n = dynamic_cast<Guardian*>(guardianList->getHead());
			bool found = false;

			while (!found) {
				if (n == nullptr) {
					cout << "Failed to find the guardian record." << endl;
					break;
				}

				if (n->getId() == check) {
					n->printDetail();
					found = true;
				}

				n = dynamic_cast<Guardian*>(n->getNext());
			}
		}
	} while (functionLoop);
}


//search for payment record
void SearchModule::searchPayment()
{
	int check = 0;
	bool functionLoop = true;
	do {
		check = InputModule::getIntegerInput("Enter the payment ID (-1 to exit):");

		if (check == -1) {
			functionLoop = false;
		}
		else {
			//check from the given order ID
			Payment* n = dynamic_cast<Payment*>(paymentList->getHead());
			bool found = false;

			while (!found) {
				if (n == nullptr) {
					cout << "Failed to find the payment record." << endl;
					break;
				}

				if (n->getId() == check) {
					n->printDetail();
					found = true;
				}

				n = dynamic_cast<Payment*>(n->getNext());
			}
		}
	} while (functionLoop);
}