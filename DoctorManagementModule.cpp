//link to other header file
#include "DoctorManagementModule.h"

DoctorManagementModule::DoctorManagementModule(List* dl)
	:doctorList(dl)
{}

//display the edit menu
void DoctorManagementModule::printEditMenu()
{
	std::cout << "---------------Edit Doctor Records--------------" << std::endl;
	std::cout << "1) ID" << std::endl;
	std::cout << "2) Name" << std::endl;
	std::cout << "3) Age" << std::endl;
	std::cout << "4) Gender" << std::endl;
	std::cout << "5) Experience Year" << std::endl;
	std::cout << "6) Experience Field" << std::endl;
	std::cout << "7) Consultant Extension" << std::endl;
	std::cout << "8) Consultation Price" << std::endl;
	std::cout << "9) Monthly salary" << std::endl;
	std::cout << "0) Back\n" << std::endl;
}


//display doctor table
void DoctorManagementModule::printDoctorTable()
{
	Doctor* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s|%-20s\n", "Index", "Doctor Name", "Experienced Field");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Doctor*>(doctorList->getHead());
	int index = 1;
	//use while loop to display until end of doctorList
	while (ptr != nullptr)
	{
		printf("%-10d|",index);
		ptr->print();
		ptr = dynamic_cast<Doctor*>(ptr->getNext());
		++index;

	}

	std::cout << line << std::endl;
}


//display all doctor records
void DoctorManagementModule::displayDoctor()
{
	const int SIZE = doctorList->size();
	bool functionLoop = true;
	do {
		printDoctorTable();
		int index = InputModule::getIntegerInput("Enter doctor index(-1 to exit): ");
		if (index == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (index >= 1 && index <= SIZE) {
			Doctor* ptr = dynamic_cast<Doctor*>(doctorList->get(index-1));
			ptr->printDetail();
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}


//add doctor record
void DoctorManagementModule::addDoctor()
{
	//input
	int id = InputModule::getIntegerInput("Enter Doctor Id : ");
	std::string name = InputModule::getStringInput("Enter Doctor Name : ");
	int age = InputModule::getIntegerInput("Enter Doctor Age : ");
	char gender = InputModule::getCharInput("Enter Doctor Gender : ");
	int experience_year = InputModule::getIntegerInput("Enter Doctor Experience Year : ");
	std::string experience_field = InputModule::getStringInput("Enter Doctor Experience Field : ");
	int consultant_extension = InputModule::getIntegerInput("Enter Doctor Consultant Extension : ");
	double consultation_price = InputModule::getDoubleInput("Enter Doctor Consultation Price : ");
	double monthly_salary = InputModule::getDoubleInput("Enter Doctor monthly salary : ");

	//create new constructor
	doctorList->add(new Doctor(id, name, age, gender, experience_year, experience_field, consultant_extension, consultation_price, monthly_salary));
	doctorList->sort();
}


//edit doctor record
void DoctorManagementModule::editDoctor()
{
	const int SIZE = doctorList->size();
	string line(50, '-');
	int input = 0;
	bool functionLoop = true;
	do {
		printDoctorTable();
		input = InputModule::getIntegerInput("Enter doctor index(-1 to exit): ");
		if (input == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (input >= 1 && input <= SIZE) {
			Doctor* ptr = dynamic_cast<Doctor*>(doctorList->get(input - 1));

			bool editLoop = true;
			do {
				cout << line << endl;
				ptr->printDetail();
				printEditMenu();

				int option = InputModule::getIntegerInput("Your option : ");

				switch (option) {
				case 1:
					ptr->setId(InputModule::getIntegerInput("Enter Doctor ID: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 2:
					ptr->setName(InputModule::getStringInput("Enter Doctor Name: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 3:
					ptr->setAge(InputModule::getIntegerInput("Enter Doctor Age: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 4:
					ptr->setGender(InputModule::getCharInput("Enter Doctor Gender[M/F]: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 5:
					ptr->setExperience_year(InputModule::getIntegerInput("Enter Doctor Experienced Year: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 6:
					ptr->setExperience_field(InputModule::getStringInput("Enter Doctor Experienced Field: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 7:
					ptr->setConsultant_extension(InputModule::getIntegerInput("Enter Doctor Consultation Extension: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 8:
					ptr->setConsultation_price(InputModule::getDoubleInput("Enter Doctor Consultation Price: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 9:
					ptr->setMonthly_salary(InputModule::getDoubleInput("Enter Doctor Monthly Salary: "));
					std::cout << "The changed has applied.\n" << endl;
					break;
				case 0:
					editLoop = false;
					break;
				default:
					std::cout << "Sorry, invalid input, please try again.";
				}
			} while (editLoop);
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}


//delete doctor record
void DoctorManagementModule::deleteDoctor()
{
	bool functionLoop = true;
	do {
		int size = doctorList->size();
		printDoctorTable();
		int index = InputModule::getIntegerInput("Enter doctor index(-1 to exit): ");
		if (index == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (index >= 1 && index <= size) {
			Doctor* ptr = dynamic_cast<Doctor*>(doctorList->get(index - 1));
			ptr->printDetail();
			bool invalid = true;
			do {
				char confirm = InputModule::getCharInput("Are you sure you want to remove the data?[Y/N] : ");

				switch (confirm) {
				case 'y':
				case 'Y':
					doctorList->remove(index - 1);
					std::cout << "The record has been removed." << std::endl;
					invalid = false;
					break;
				case 'x':
				case 'X':
					std::cout << "The record was not removed." << std::endl;
					invalid = false;
					break;
				default:
					std::cout << "Invalid input! Please try again!" << std::endl;
				}

			} while (invalid);
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}

void DoctorManagementModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Doctor Management Module" << endl;
	cout << line << endl;
	cout << "1 -> Add new Doctor Data" << endl;
	cout << "2 -> Edit Doctor Data" << endl;
	cout << "3 -> Delete Doctor Data" << endl;
	cout << "4 -> View Doctor Data" << endl;
	cout << "5 -> Return to Main Menu" << endl;
	cout << line << endl;
}

void DoctorManagementModule::mainProcess(int input) {
	switch (input) {
	case 1:
		addDoctor();
		break;
	case 2:
		editDoctor();
		break;
	case 3:
		deleteDoctor();
		break;
	case 4:
		displayDoctor();
		break;
	case 5:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}