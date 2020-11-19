#pragma once
#include "Module.h"
#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Guardian.h"
#include "Patient.h"
#include "Payment.h"
#include "Medicine.h"
#include "Doctor.h"

/*
	HTML Exportation Module of the system:
	In this system, the user can export the data in html format including:
	-patient
	-guardian
	-doctor
	-medicine
	-payment
*/
class HTMLExportationModule :
    public Module
{
private:
	//The starting line of html file
	const std::string htmlStart = "<!DOCTYPE html><html lang='en'><body><table>";
	//The ending line of html file
	const std::string htmlEnd = "</table></body></html>";
	//list of doctor records
	List* doctorList;
	//list of patient records
	List* patientList;
	//list of guardian records
	List* guardianList;
	//list of medicine records
	List* medicineList;
	//list of payment records
	List* paymentList;
public:
	/*
		The constructor required all the list in the program
		the pointer to the list will be saved as the private field
		and used in the data exportation

		@param - dl : the list of doctor record
		@param - pl : the list of patient record
		@param - gl : the list of guardian record
		@param - ml : the list of medicine record
		@param - paymentl : the list of payment record
	*/
	HTMLExportationModule(List* dl, List* pl, List* gl, List* ml, List* paymentl);

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

	/*
		This method is used to export the patient data into the file
		@return - the status of export process (return false if exception occur)
	*/
	bool exportPatient();
	/*
		This method is used to export the guardian data into the file
		@return - the status of export process (return false if exception occur)
	*/
	bool exportGuardian();
	/*
		This method is used to export the medicine data into the file
		@return - the status of export process (return false if exception occur)
	*/
	bool exportMedicine();
	/*
		This method is used to export the doctor data into the file
		@return - the status of export process (return false if exception occur)
	*/
	bool exportDoctor();
	/*
		This method is used to export the payment data into the file
		@return - the status of export process (return false if exception occur)
	*/
	bool exportPayment();


};

