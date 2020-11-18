#pragma once
#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "InputModule.h"
#include "Node.h"
#include "Guardian.h"
#include "Patient.h"
#include "Payment.h"
#include "Medicine.h"
#include "Doctor.h"

/*
	This is an extra module which used to deal with the file handling process
	such as read and write data
*/
class FileManagementModule
{
private:
	List* doctorList;
	List* patientList;
	List* guardianList;
	List* medicineList;
	List* paymentList;
public:
	/*
		Used when reading data from files in FileManagementModule
	*/
	const static int READMODE = 0;
	/*
		Used when writing data into files in FileManagementModule
	*/
	const static int WRITEMODE = 1;
	/*
		The constructor required all the list in the program
		the pointer to the list will be saved as the private field
		and used in the file reading and saving

		@param - dl : the list of doctor record
		@param - pl : the list of patient record
		@param - gl : the list of guardian record
		@param - ml : the list of medicine record
		@param - paymentl : the list of payment record
		@param - mode : the mode of process which should called based on the constant provided in this class
	*/
	FileManagementModule(List* dl, List* pl, List* gl, List* ml, List* paymentl, int mode);

	/*
		This method is used to save the patient data into the file
		@return - the status of writing process (return false if exception occur)
	*/
	bool savePatient();
	/*
		This method is used to save the guardian data into the file
		@return - the status of writing process (return false if exception occur)
	*/
	bool saveGuardian();
	/*
		This method is used to save the medicine data into the file
		@return - the status of writing process (return false if exception occur)
	*/
	bool saveMedicine();
	/*
		This method is used to save the doctor data into the file
		@return - the status of writing process (return false if exception occur)
	*/
	bool saveDoctor();
	/*
		This method is used to save the payment data into the file
		@return - the status of writing process (return false if exception occur)
	*/
	bool savePayment();

	/*
		This method is used to load the patient data from the file
		@return - the status of reading process (return false if exception occur)
	*/
	bool loadPatient();
	/*
		This method is used to load the guardian data from the file
		@return - the status of reading process (return false if exception occur)
	*/
	bool loadGuardian();
	/*
		This method is used to load the medicine data from the file
		@return - the status of reading process (return false if exception occur)
	*/
	bool loadMedicine();
	/*
		This method is used to load the doctor data from the file
		@return - the status of reading process (return false if exception occur)
	*/
	bool loadDoctor();
	/*
		This method is used to load the payment data from the file
		@return - the status of reading process (return false if exception occur)
	*/
	bool loadPayment();
};

