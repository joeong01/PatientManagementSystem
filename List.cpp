#include "List.h"

List::List() {
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

bool List::isEmpty() {
	return length == 0;
}

bool List::add(Node* n) {
	if (this->isEmpty()) {
		this->head = n;
		this->tail = n;
	}
	else {
		this->tail->setNext(n);
		n->setPrev(this->tail);
		this->tail = n;
	}
	++length;
}

bool List::insert(Node* n, int index) {
	if (index<0 || index > length)
		return false;

	if (index == 0) {
		Node* target = this->head;
		target->setPrev(n);
		this->head = target;
	}
	Node* prev = this->get(index-1);
	Node* next = this->get(index);
	prev->setNext(n);
	next->setPrev(n);

	++length;

}

bool List::remove(int index) {
	if (index<0 || index > length) {
		return false;
	}
	Node* target = this->get(index);
	Node* prev = target->getPrev();
	Node* next = target->getNext();
	prev->setNext(next);
	next->setPrev(prev);
	delete target;
	--length;

	return true;
}

bool List::swap(int n1, int n2) {
	Node* node1 = nullptr;
	Node* node2 = nullptr;

	if (n1<0 || n2<0 || n1 > length || n2 > length) {
		return false;
	}

	if (n1 > n2) {
		node1 = this->get(n2);
		node2 = this->get(n1);
	}
	else {
		node1 = this->get(n1);
		node2 = this->get(n2);
	}

	Node* beforeNode2 = node2->getPrev();
	Node* afterNode2 = node2->getNext();

	if (node1 == this->head) {
		Node* afterNode1 = node1->getNext();
		afterNode1->setPrev(node2);
		node2->setNext(afterNode1);
		node2->setPrev(nullptr);
		this->head = node2;
	}
	else {
		Node* beforeNode1 = node1->getPrev();
		Node* afterNode1 = node1->getNext();

		beforeNode1->setNext(node2);
		afterNode1->setPrev(node2);
		node2->setNext(afterNode1);
		node2->setPrev(beforeNode1);
	}

	if (afterNode2 == nullptr) {
		beforeNode2->setNext(node1);
		node1->setNext(nullptr);
		node1->setPrev(beforeNode2);
		this->tail = node1;
	}
	else {
		beforeNode2->setNext(node1);
		afterNode2->setPrev(node1);
		node1->setNext(afterNode2);
		node1->setPrev(beforeNode2);
	}

	return true;
}

bool List::sort() {
	bool sorted = true;

	for (int i = 0; i < length-1; ++i) {
		sorted = true;
		for (int j = i; j < length-1; ++j) {
			if (this->get(j) > this->get(j + 1)) {
				this->swap(j, j+1);
				sorted = false;
			}
		}
		if (sorted)
			break;
	}
	return true;
}

Node* List::get(int index) {
	if (index<0 || index > length)
		return nullptr;
	
	Node* target = nullptr;
	if (index > length / 2) {
		target = this->tail;
		int move = length - index;
		for (int i = length-1; i > move; --i) {
			target = target->getPrev();
		}
	}
	else {
		target = this->head;
		for (int i = 0; i < index; ++i) {
			target = target->getNext();
		}
	}

	return target;
}

int List::size() {
	return length;
}

Node* List::getHead() {
	return head;
}

Node* List::getTail() {
	return tail;
}