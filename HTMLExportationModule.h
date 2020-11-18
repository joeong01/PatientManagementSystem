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

class HTMLExportationModule :
    public Module
{
private:
	const std::string htmlStart = "<!DOCTYPE html><html lang='en'><body><table>";
	const std::string htmlEnd = "</table></body></html>";
	List* doctorList;
	List* patientList;
	List* guardianList;
	List* medicineList;
	List* paymentList;
public:
	HTMLExportationModule(List* dl, List* pl, List* gl, List* ml, List* paymentl);

	/*
		This abstract method is used to display the main menu
		in each module and should be printed in beginning of each loop
		of the module
	*/
	void printMainMenu();

	/*
		This abstract method is the main process of the module
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

