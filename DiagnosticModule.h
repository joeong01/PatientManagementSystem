#pragma once
#include <iostream>
#include "Module.h"
#include "List.h"
#include "InputModule.h"
#include "Doctor.h"
#include "Patient.h"
#include "Medicine.h"

/*
    Diagnostic Module of the system: 
    In this system, the doctor can save the diagnostic result of patients including:
    -add new patient
    -set illness description
    -add medicine of patient

    Also, the doctor can check the patients diagnostic result
*/
class DiagnosticModule :
    public Module
{
private:
    List* doctorList;
    List* patientList;
    List* medicineList;
public:
    /*
        The constructor of Diagnostic Module
        called when enter this module.
        The list of doctor, patient and medicine is required
        @param - dl : list of doctor
        @param - pl : list of patient
        @param - ml : list of medicine
    */
    DiagnosticModule(List* dl, List* pl, List* ml);

    void diagnose();
    void checkDiagnose();

    void printMainMenu();
    void mainProcess(int input);

    void printPatientList();
    void printMedicineList();
    void printDoctorList();
};

