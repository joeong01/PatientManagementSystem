#pragma once
#include "Module.h"
#include "List.h"
#include <iostream>
#include <string>

class PaymentModule
	: public Module
{
private:
	List* patientList;
	List* medicineList;
	List* doctorList;
public:
	PaymentModule(List* pl, List* ml, List* dl);
	void printMainMenu();
	void mainProcess(int input);
};