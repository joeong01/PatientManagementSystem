#pragma once
#include <string>

/*
	Printable class is an interface which provide the ability of display details of the record.
*/
class Printable
{
public:
	/*
		This method will print the simplified detail of the
		object which is mainly used in the table display
	*/
	virtual void print() = 0;

	/*
		This method will print the full detail of the object
		in line-by-line format
	*/
	virtual void printDetail() = 0;

	/*
		This method will print all the detail of object in a line
		with semicolon(;) as deliminator which allow the data to be saved into the
		.dat format
	*/
	virtual std::string toString() = 0;
};

