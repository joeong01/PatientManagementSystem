#pragma once
#include "Node.h"

/*
    Doctor class is used to store the information of Doctor
    which carry characteristics of Node so that the Doctor can be stored in form of List
*/
class Doctor :
    public Node
{
public:
    std::string getName();

    void print();
    void printDetail();
    std::string toString();
    bool operator <(Node& tmp);
};

