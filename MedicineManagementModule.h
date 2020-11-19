#pragma once
#include "List.h"
#include "Medicine.h"
#include "InputModule.h"
#include <iomanip>
#include "Module.h"
using namespace std;

/*
	Medicine Management Module of the system:
	In this module, the user can modify the medicine data including:
	-add new medicine data
	-edit medicine data
	-delete medicine data
	-view medicine data
*/
class MedicineManagementModule : public Module{
private:
	//list of medicine records
	List* medicineList;

public:
	/*
		The constructor required the list of medicine record in the program
		the pointer to the list will be saved as the private field
		and used in the data modification

		@param - ml : the list of medicine record
	*/
	MedicineManagementModule(List* ml);

	/*
		This method will display a simplified information of all medicine record in the list
		in table format
	*/
	void printMedicineTable();

	/*
		This method provide the function of add new medicine record into the list
	*/
	void addMedicine();

	/*
		This method provide the function of edit medicine record in the list
	*/
	void modifyMedicine();

	/*
		This method provide the function of remove medicine record from the list
	*/
	void removeMedicine();

	/*
		This method allow the user to view the full details of the medicine record
	*/
	void displayMedicine();

	/*
		This method is used to display the main menu
		of the module and should be printed in beginning of each loop
		of the module
	*/
	void printMainMenu();

	/*
		This method is the main process of the module
		which the action will be selected based on the user input
		in this module

		@param - input : The choice of user based on the main menu
	*/
	void mainProcess(int input);
};