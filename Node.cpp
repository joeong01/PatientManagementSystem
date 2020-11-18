#include "Node.h"

//body of getter & setter
Node* Node::getNext() { return next; }
Node* Node::getPrev() { return prev; }

void Node::setNext(Node* a) { this->next = a; }
void Node::setPrev(Node* a) { this->prev = a; }