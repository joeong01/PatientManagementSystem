#include "MainModule.h"
#include "InputModule.h"
#include "FileManagementModule.h"


int main(int argc, char** argv) 
{
	FileManagementModule* f = nullptr;
	List* doctorList = new List();
	List* patientList = new List();
	List* medicineList = new List();
	List* guardianList = new List();
	List* paymentList = new List();

	
	f = new FileManagementModule(
			doctorList,
			patientList,
			guardianList,
			medicineList,
			paymentList,
			FileManagementModule::READMODE
		);
	
	delete f;
	

	MainModule m(patientList,doctorList,medicineList,guardianList,paymentList);

	do {
		m.printMainMenu();
		int choice = InputModule::getIntegerInput("Your option : ");
		m.mainProcess(choice);
	} while (m.isContinue());

	f = new FileManagementModule(
		doctorList,
		patientList,
		guardianList,
		medicineList,
		paymentList,
		FileManagementModule::WRITEMODE
	);

	delete f;

	return 0;
}