#pragma once
#include "Module.h"
#include "List.h"
#include "InputModule.h"
#include "Payment.h"
#include "Patient.h"
#include "Doctor.h"
#include "Medicine.h"
#include <iostream>
#include <string>
#include <ctime>

class PaymentModule
	: public Module
{
private:
	List* patientList;
	List* medicineList;
	List* doctorList;
	List* paymentList;
public:
	PaymentModule(List* pl, List* ml, List* dl, List* paymentlist);
	void printPaymentTable();
	void printPatientTable();
	void printMainMenu();
	void mainProcess(int input);
	void makePayment();
	void displayPayment();
	double calculateTotalPrice(Patient* patient);
};