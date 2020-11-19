#pragma once
#include "List.h"
#include "Doctor.h"
#include "Patient.h"
#include "Medicine.h"
#include "Guardian.h"
#include "Payment.h"
#include "InputModule.h"
#include "Module.h"

class SearchModule : public Module{
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
        The constructor of Search Module
        called when enter this module.
        @param - pl : list of patient record
        @param - dl : list of doctor record
        @param - ml : list of medicine record
        @param - gl : list of guardian record
        @param - payment : list of payment record
    */
    SearchModule(List* pl, List* dl, List* ml, List* gl, List* payment);

    void searchDoctor();
    void searchPatient();
    void searchMedicine();
    void searchGuardian();
    void searchPayment();

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

