#pragma once
#include "List.h"
#include <string>
#include "Medicine.h"
#include "InputModule.h"
#include "Patient.h"
#include <iomanip>
#include "Guardian.h"
#include "Module.h"
using namespace std;
/*
	Patient Management Module of the system:
	In this module, the user can modify the patient data including:
	-add new patient
	-edit patient data
	-delete patient data
	-view patient data
	-edit guardian data
	-delete guardian data
	-view guardian data
*/
class PatientManagementModule : public Module {
private:
	//list of patient and guardian record
	List* patientList;
	List* guardianList;

public:
	/*
		The constructor required the list of patient record in the program
		the pointer to the list will be saved as the private field and used in the
		data modification
		@param - pl : the list of patient
	*/
	PatientManagementModule(List* pl, List* gl);
	/*
		This method will display a simplified information of all patient record in the list in table format
	*/
	void printPatientTable();
	/*
		This methid will display a simplified information of all guardian record in the list in tabe format
	*/
	void printGuardianTable();
	/*
		This method provide the function of add new patient record into the list
	*/
	void addPatient();
	/*
		This method provide the function of edit patient record from the list
	*/
	void modifyPatient();
	/*
		This method provide the function of remove patient record from the list
	*/
	void removePatient();
	/*
		This method allow the user to view the full details of the patient record
	*/
	void displayPatient();
	/*
		This method provide the function of edit guardian record from the list
	*/
	void modifyGuardian();
	/*
		This method provide the function of remove guardian record from the list
	*/
	void removeGuardian();
	/*
		This method allow the user to view the full detials of the  guardian record
	*/
	void displayGuardian();
	/*
		This method is used to display the main menu of the module and should be printed
		in behining of each loop of the module
	*/
	void printMainMenu();
	/*
		This method is the mian process of the module which the action will be selected
		based on the user input in this module
		@param - input : The choice od user based on main menu
	*/
	void mainProcess(int input);
};