#include"MedicineManagementModule.h"


MedicineManagementModule::MedicineManagementModule(List* ml) 
	:medicineList(ml)
{}

void MedicineManagementModule::printMedicineTable()
{
	Medicine* ptr = nullptr;
	std::string line(50, '-');

	printf("%-10s|%-20s\n", "Index", "Medicine Name");
	std::cout << line << std::endl;

	ptr = dynamic_cast<Medicine*>(medicineList->getHead());
	int index = 1;
	//use while loop to display until end of medicineList
	while (ptr != nullptr)
	{
		printf("%-10d|", index);
		ptr->print();
		ptr = dynamic_cast<Medicine*>(ptr->getNext());
		++index;
	}

	std::cout << line << std::endl;
}


void MedicineManagementModule::addMedicine()
{
	int id = 0;
	double price = 0;
	string name("");

	id = InputModule::getIntegerInput("Enter Medicine ID: ");
	name = InputModule::getStringInput("Enter Medicine Name: ");
	price = InputModule::getDoubleInput("Enter Medicine Price: ");

	//create medicine data
	Node* medicine = new Medicine(id, name, price);
	medicineList->add(medicine);
	medicineList->sort();
}


void MedicineManagementModule::modifyMedicine()
{
	const int SIZE = medicineList->size();
	string line(50, '-');
	int input = 0;
	bool functionLoop = true;
	do {
		printMedicineTable();
		input = InputModule::getIntegerInput("Enter medicine index(-1 to exit): ");
		if (input == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (input >= 1 && input <= SIZE) {
			Medicine* ptr = dynamic_cast<Medicine*>(medicineList->get(input - 1));
			
			bool editLoop = true;
			do {
				cout << line << endl;
				ptr->printDetail();
				cout << "---------------Edit Medicine Records--------------" << endl;
				cout << "1) ID" << endl;
				cout << "2) Name" << endl;
				cout << "3) Price" << endl;
				cout << "4)Exit\n" << endl;

				int option = InputModule::getIntegerInput("Your option : ");

				switch (option) {
				case 1:
					ptr->setId(InputModule::getIntegerInput("Enter Medicine ID: "));
					cout << "Applied changes!" << endl;
					break;
				case 2:
					ptr->setName(InputModule::getStringInput("Enter Medicine Name: "));
					cout << "Applied changes!" << endl;
					break;
				case 3:
					ptr->setPrice(InputModule::getDoubleInput("Enter Medicine Price: "));
					cout << "Applied changes!" << endl;
					break;
				case 4:
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


void MedicineManagementModule::removeMedicine()
{
	bool functionLoop = true;
	do {
		int size = medicineList->size();
		printMedicineTable();
		int index = InputModule::getIntegerInput("Enter medicine index(-1 to exit): ");
		if (index == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (index >= 1 && index <= size) {
			Medicine* ptr = dynamic_cast<Medicine*>(medicineList->get(index - 1));
			ptr->printDetail();
			bool invalid = true;
			do {
				char confirm = InputModule::getCharInput("Are you sure you want to remove the data?[Y/N] : ");

				switch (confirm) {
				case 'y':
				case 'Y':
					medicineList->remove(index - 1);
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

void MedicineManagementModule::displayMedicine()
{
	const int SIZE = medicineList->size();
	bool functionLoop = true;
	do {
		printMedicineTable();
		int index = InputModule::getIntegerInput("Enter medicine index(-1 to exit): ");
		if (index == -1) {
			cout << "Returning to Module Menu" << endl;
			functionLoop = false;
		}
		else if (index >= 1 && index <= SIZE) {
			Medicine* ptr = dynamic_cast<Medicine*>(medicineList->get(index - 1));
			ptr->printDetail();
		}
		else {
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (functionLoop);
}

void MedicineManagementModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Medicine Management Module" << endl;
	cout << line << endl;
	cout << "1 -> Add new Medicine Data" << endl;
	cout << "2 -> Edit Medicine Data" << endl;
	cout << "3 -> Delete Medicine Data" << endl;
	cout << "4 -> View Medicine Data" << endl;
	cout << "5 -> Return to Main Menu" << endl;
	cout << line << endl;
}

void MedicineManagementModule::mainProcess(int input) {
	switch (input) {
	case 1:
		addMedicine();
		break;
	case 2:
		modifyMedicine();
		break;
	case 3:
		removeMedicine();
		break;
	case 4:
		displayMedicine();
		break;
	case 5:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}