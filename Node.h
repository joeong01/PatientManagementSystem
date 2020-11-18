#pragma once
#include "Printable.h"

/*
* Node class is the base class of the data which provide the
* node elements to the classes which stores the data in the system.
* This class is required to form a doubly-linked list
*/
class Node : public Printable
{
	Node* next;
	Node* prev;

public:
	Node* getNext();
	Node* getPrev();

	void setNext(Node*);
	void setPrev(Node*);

	virtual bool operator <(Node& n) = 0;
};