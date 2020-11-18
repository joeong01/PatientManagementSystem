#pragma once
#include "Node.h"
#include <string>
using namespace std;

/*
    Medicine class is used to store the information of Medicines
    which carry characteristics of Node so that the Medicine can be stored in form of List
*/
class Medicine : public Node
{
//private attribute
	int id;
	string name;
	double price;

//public attribute
public:
    //prototype of overloaded constructor
    Medicine(int id, string name, double price);

    //prototpye of getter & setter
    int getId();
    void setId(int id);

    string getName();
    void setName(string name);

    double getPrice();
    void setPrice(double price);

    void print();
    void printDetail();
    std::string toString();

    bool operator < (Node& tmp);
};

