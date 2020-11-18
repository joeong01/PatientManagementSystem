#include "DiagnosticModule.h"

DiagnosticModule::DiagnosticModule(List* dl, List* pl, List* ml)
	:doctorList(dl), patientList(pl), medicineList(ml)
{}

void DiagnosticModule::printDoctorList() {
	using namespace std;
	string line(50, '-');
	const int DOCTORSIZE = doctorList->size();

	cout << line << endl;
	printf("%-5s|%-20s\n", "index", "doctor");
	cout << line << endl;
	for (int i = 0; i < DOCTORSIZE; ++i) {
		Doctor* record = dynamic_cast<Doctor*>(patientList->get(i));
		printf("%-5d|%-20s\n", i + 1, record->getName());
	}
	printf("Enter %d to return\n", DOCTORSIZE);
	cout << line << endl;
}

void DiagnosticModule::printPatientList() {
	using namespace std;
	string line(50, '-');
	const int PATIENTSIZE = patientList->size();

	cout << line << endl;
	printf("%5s|%20s\n", "index", "patient");
	cout << line << endl;
	for (int i = 0; i < PATIENTSIZE; ++i) {
		Patient* record = dynamic_cast<Patient*>(patientList->get(i));
		printf("%-5d|%-20s\n", i + 1, record->getName());
	}
	cout << line << endl;
}

void DiagnosticModule::printMedicineList() {
	using namespace std;
	string line(50, '-');
	const int MEDICINESIZE = medicineList->size();

	cout << line << endl;
	printf("%5s|%20s\n", "index", "medicine");
	cout << line << endl;
	for (int i = 0; i < MEDICINESIZE; ++i) {
		Medicine* record = dynamic_cast<Medicine*>(medicineList->get(i));
		printf("%-5d|%-20s\n", i + 1, record->getName());
	}
	cout << line << endl;
}

void DiagnosticModule::diagnose() {

	int option = 0;
	const int PATIENTSIZE = patientList->size();
	const int DOCTORSIZE = doctorList->size();
	const int MEDICINESIZE = medicineList->size();
	bool functionLoop = true;
	bool valid = true;

	while (valid) {

		printDoctorList();
		int doctorIndex = InputModule::getIntegerInput("Enter your doctor_index:");

		if (doctorIndex > DOCTORSIZE) {
			std::cout << "Invalid index. Please try again." << std::endl;
		}

		else {
			break;
		}

	}

	do {
		printPatientList();
		int patientIndex = InputModule::getIntegerInput("Enter patient_index : ");

		if (patientIndex == PATIENTSIZE + 1) {
			std::cout << "Returning to Diagnostic Module..." << std::endl;
			functionLoop = false;
		}
		else if (patientIndex > 0 && patientIndex <= PATIENTSIZE) {
			string description = "";
			Patient* patient_ptr = dynamic_cast<Patient*>(patientList->get(patientIndex - 1));
			patient_ptr->printDetail();

			string illness = InputModule::getStringInput("Please enter patient's illness description:");

			while (valid) {

				printMedicineList();
				int medicineIndex = InputModule::getIntegerInput("Enter medicine_index:");

				if (medicineIndex > MEDICINESIZE) {
					std::cout << "Invalid index. Please try again." << std::endl;
				}

				else {
					break;
				}

			}
			patient_ptr->setIllness(temp);
			patient_ptr->setDoctorName(doctorList->get(doctorIndex));
			Medicine* medicine_ptr = dynamic_cast<Medicine*>(medicineList->get(medicineIndex - 1));
			patient_ptr->getMedicine().add(new Medicine(*medicine_ptr));

			std::cout << "Data entered sucessful" << std::endl;
			functionLoop = false;


		}
		else {
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (functionLoop);




}

void DiagnosticModule::checkDiagnose() {
	int option = 0;
	const int PATIENTSIZE = patientList->size();
	bool functionLoop = true;

	do {
		printPatientList();
		int patientIndex = InputModule::getIntegerInput("Enter your patient_index : ");

		if (patientIndex == PATIENTSIZE + 1) {
			std::cout << "Returning to Diagnostic Module..." << std::endl;
			functionLoop = false;
		}
		else if (patientIndex > 0 && patientIndex <= PATIENTSIZE) {
			Patient* patient_ptr = dynamic_cast<Patient*>(patientList->get(patientIndex - 1));
			patient_ptr->printDetail();
			cout << string(50, '-') << endl;
		}
		else {
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (functionLoop);

}

void DiagnosticModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Diagnostic Module" << endl;
	cout << line << endl;
	cout << "1 -> Diagnose" << endl;
	cout << "2 -> Check Diagnostic Record" << endl;
	cout << "3 -> Return to Main Menu" << endl;
	cout << line << endl;
}

void DiagnosticModule::mainProcess(int input) {
	switch (input) {
	case 1:
		this->diagnose();
		break;
	case 2:
		this->checkDiagnose();
		break;
	case 3:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}
