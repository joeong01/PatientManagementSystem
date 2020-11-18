#pragma once
#include <string>
#include <iostream>
#include <iostream>
#include <queue>

/*
	This is an extra module which used to get the user input
	and handle the exceptions due to the user input.
	All the methods in this module are static which the methods can
	be called directly without create any instance.
*/
class InputModule
{
private:
	/*
		The size of character ignored if invalid input is caught
	*/
	const static int ignoreSize = 1024;
public:
	/*
		This method is used to get the integer input from the user.
		@param - prompt : the text displayed to inform the user about the input field
		@return - the valid user input in 'int' datatype
	*/
	static int getIntegerInput(std::string prompt);
	/*
		This method is used to get the char input from the user.
		@param - prompt : the text displayed to inform the user about the input field
		@return - the valid user input in 'char' datatype
	*/
	static char getCharInput(std::string prompt);

	/*
		This method is used to get the string input from the user.
		@param - prompt : the text displayed to inform the user about the input field
		@return - the valid user input in 'std::string' datatype
	*/
	static std::string getStringInput(std::string prompt);

	/*
		This method is used to get the double input from the user.
		@param - prompt : the text displayed to inform the user about the input field
		@return - the valid user input in 'double' datatype
	*/
	static double getDoubleInput(std::string prompt);

	/*
		This method is used to get the split the string input from the file.
		@param - input : the input string from the file
		@param - delimiter : the character to split the data (default = ';')
		@return - the queue with splited strings based on the deliminater of ';'
	*/
	static std::queue<std::string> split_string(std::string input,const char delimiter = ';');
};

