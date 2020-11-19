#pragma once
#include "List.h"
#include "Module.h"
#include <string>
#include "Medicine.h"
#include "InputModule.h"
#include "Patient.h"
#include <iomanip>
#include "Guardian.h"

class PatientManagementModule 
	:public Module
{
private:
	List* patientList;
	List* guardianList;

public:
	PatientManagementModule(List* pl, List* gl);
	void printPatientTable();
	void printGuardianTable();
	void addPatient();
	void modifyPatient();
	void removePatient();
	void displayPatient();
	void modifyGuardian();
	void removeGuardian();
	void displayGuardian();

	void printMainMenu();
	void mainProcess(int input);
};