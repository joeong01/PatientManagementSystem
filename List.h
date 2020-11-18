#pragma once
#include "Node.h"

class List
{
private:
	/*
		The pointer points to the beginning node of the list
	*/
	Node* head;
	/*
		The pointer points to the ending node of the list
	*/
	Node* tail;
	/*
		The number of nodes linked in the list
	*/
	int length;
public:
	/*
		The constructor of List which will initialize head and tail to nullptr and length to 0
	*/
	List();
	/*
		Check if the list is empty(length ==0)
		@return - true if the length is 0
	*/
	bool isEmpty();

	/*
		Append the node to the end of the list
		@param - n : the node to be append into the list
		@return - the status of append, false if exception occur
	*/
	bool add(Node* n);

	/*
		Insert the node into the fixed index
		@param - n : the node to be inserted into the list
		@param - index : the index of the node to be inserted
		@return - status of the insertion, false if exception occur
	*/
	bool insert(Node* n, int index);

	/*
		Remove the node at the index in the list
		@param - index : the index of the node to be removed
		@return - status of the deletion, false if exception occur
	*/
	bool remove(int index);

	/*
		Sort the node in the list based on the '<' operator of the data
		@return - status of the sorting, false if exception occur
	*/
	bool sort();

	/*
		Return the specific node in the list
		@param - index : the index of the node to be returned
		@return - a pointer to the specific node in the list(null pointer if not found)
	*/
	Node* get(int index);

	/*
		get the number of node in the list currently
		@return - number of node in the list
	*/
	int size();

	/*
		Get the starting node of the list
		@return - the starting node of the list
	*/
	Node* getHead();

	/*
		Get the ending node of the list
		@return - the ending node of the list
	*/
	Node* getTail();

	/*
		Swap the location of the two nodes in the linked list
		@param - n1 : first node
		@param - n2 : second node
	*/
	bool swap(int n1, int n2);
};

