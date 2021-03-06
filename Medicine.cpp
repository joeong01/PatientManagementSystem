#include "Medicine.h"

Medicine::Medicine(int id, string name, double price) {
	this->setId(id);
	this->setName(name);
	this->setPrice(price);
}

int Medicine::getId() { return id; }
void Medicine::setId(int id) { this->id = id; }

string Medicine::getName() { return name; }
void Medicine::setName(string name) { this->name = name; }

double Medicine::getPrice() { return price; }
void Medicine::setPrice(double price) { this->price = price; }

std::string Medicine::toString() {
	return std::to_string(this->id) + ";" + name + ";" + std::to_string(this->price);
}

void Medicine::print() {
	printf("%-20s\n", name.c_str());
}

void Medicine::printDetail() {
	cout << "Medicine Id : " << id << endl;
	cout << "Medicine Name : " << name << endl;
	cout << "Medicine Price : " << price << endl;
}

bool Medicine::operator < (Node& tmp) {
	Medicine& m = dynamic_cast<Medicine&>(tmp);
	return this->id < m.id;
}