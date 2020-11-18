#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

/*
    Payment class is used to store the information of Payment
    which carry characteristics of Node so that the Payment record can be stored in form of List
*/
class Payment : public Node
{
//private attribute
	int id;
	string patient_name;
	string date;
	double totalPrice;

//public attribute
public:
    Payment(int id, string patient_name, string date, double totalPrice);

    int getId();
    void setId(int);

    string getPatientName();
    void setPatientName(string patient_name);

    string getDate();
    void setDate(string);

    double getTotalPrice();
    void setTotalPrice(double);

    void print();
    void printDetail();
    std::string toString();
    bool operator <(Node& tmp);
};

