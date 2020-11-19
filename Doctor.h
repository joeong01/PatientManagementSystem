#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

//create a class of Doctor
class Doctor :
    public Node
{
    //private variables
    int id, age, experience_year, consultant_extension;
    double monthly_salary, consultation_price;
    string name, experience_field;
    char gender;

public:

    //declaration of Doctor overloaded constructor
    Doctor(int, string, int, char, int, string, int, double, double);

    //declaration of getter, setter function prototype
    int getId();
    int getAge();
    int getExperience_year();
    int getConsultant_extension();
    double getMonthly_salary();
    double getConsultation_price();
    string getName();
    string getExperience_field();
    char getGender();

    void setId(int);
    void setAge(int);
    void setExperience_year(int);
    void setConsultant_extension(int);
    void setMonthly_salary(double);
    void setConsultation_price(double);
    void setName(string);
    void setExperience_field(string);
    void setGender(char);

    void print();
    void printDetail();
    std::string toString();
    bool operator <(Node& tmp);
};
