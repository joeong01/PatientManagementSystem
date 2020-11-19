#pragma once
#include "List.h"
#include "Doctor.h"
#include "Module.h"
#include "InputModule.h"
#include <iostream>
#include "List.h"
#include <iomanip>
#include <string>

/*
	Doctor Management Module of the system:
	In this module, the user can modify the doctor data including:
	-add new doctor data
	-edit doctor data
	-delete doctor data
	-view doctor data
*/
class DoctorManagementModule : public Module{
private:
	//list of doctor records
	List* doctorList;

public:
	/*
		The constructor required the list of doctor record in the program
		the pointer to the list will be saved as the private field
		and used in the data modification

		@param - dl : the list of doctor record
	*/
	DoctorManagementModule(List* dl);

	/*
		This method will display a simplified information of all doctor record in the list
		in table format
	*/
	void printDoctorTable();

	/*
		This method provide the function of add new doctor record into the list
	*/
	void addDoctor();

	/*
		This method provide the function of edit doctor record in the list
	*/
	void editDoctor();

	/*
		This method provide the function of remove doctor record from the list
	*/
	void deleteDoctor();
    
	/*
		This method allow the user to view the full details of the doctor record
	*/
	void displayDoctor();

	/*
		This method is used to display the main menu
		of the module and should be printed in beginning of each loop
		of the module
	*/
	void printMainMenu();

	/*
		This method is used to provide a list of option for user to select if edit any field 
		of doctor record
	*/
	void printEditMenu();

	/*
		This method is the main process of the module
		which the action will be selected based on the user input
		in this module

		@param - input : The choice of user based on the main menu
	*/
	void mainProcess(int input);
};