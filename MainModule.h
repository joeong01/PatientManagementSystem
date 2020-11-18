#pragma once
#include "Module.h"
#include "DiagnosticModule.h"
#include "List.h"
#include "InputModule.h"
#include "HTMLExportationModule.h"
#include <iostream>

/*
    The main module of the patient management system which
    will ask user to choose and direct the user to the module selected
*/
class MainModule :
    public Module
{
private:
    //the list of doctor record
    List* doctorList;
    //the list of patient record
    List* patientList;
    //the list of medicine record
    List* medicineList;
    //the list of guardian record
    List* guardianList;
    //the list of payment record
    List* paymentList;
public:
    /*
        The constructor of Main Module
        called when enter this module.
        @param - pl : list of patient record
        @param - dl : list of doctor record
        @param - ml : list of medicine record
        @param - gl : list of guardian record
        @param - payment : list of payment record
    */
    MainModule(List* pl, List* dl, List* ml, List* gl, List* payment);
    /*
        This method is used to display the main menu
        in the module to let the user to select the module entered
        and should be printed in beginning of each loop of the module
    */
    void printMainMenu();

    /*
        This abstract method is the main process of the module
        which the action will be selected based on the user input
        in this module

        @param - input : The choice of user based on the main menu
    */
    void mainProcess(int input);
};

