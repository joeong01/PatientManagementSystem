#pragma once

/*
	Module class is the main framework which should be inherit by
	each module in this program to ensure the basic functionality of
	the modules in the program
*/
class Module
{
private:
	/*
		The current status of the module
		true - the module is running
		false - the module had been terminated and ready to return to last module
	*/
	bool loop;
public:
	/*
		This constructor is used to initialize the
		loop instance to true which indicate the module is running.
	*/
	Module();

	/*
		This abstract method is used to display the main menu
		in each module and should be printed in beginning of each loop
		of the module
	*/
	virtual void printMainMenu() = 0;

	/*
		This abstract method is the main process of the module
		which the action will be selected based on the user input
		in this module

		@param - input : The choice of user based on the main menu
	*/
	virtual void mainProcess(int input) = 0;

	/*
		This method is called to terminate the module and return to
		last module
	*/
	void endProcess();

	/*
		This method is called to determine if the method is running or
		already terminated.
		@return - the status of module
	*/
	bool isContinue();
};

