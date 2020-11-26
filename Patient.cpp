#include "Patient.h"

//body of overload constructor
Patient::Patient(int id, int age, string name, string address, string contact, string illness, bool insurance, string doctor_name, string medicine) {
	this->setId(id);
	this->setAge(age);
	this->setName(name);
	this->setAddress(address);
	this->setContact(contact);
	this->setDoctorName(doctor_name);
	this->setInsurance(insurance);
	this->setMedicine(medicine);
}

//body of getter & setter
int Patient::getId() { return id; }
int Patient::getAge() { return age; }
string Patient::getName() { return name; }
string Patient::getAddress() { return address; }
string Patient::getContact() { return contact;}
string Patient::getIllness() { return illness; }
string Patient::getDoctorName() { return doctor_name; }
bool Patient::getInsurance() { return insurance; }
string Patient::getMedicine() { return medicine; }


void Patient::setId(int id){ this->id = id;}
void Patient::setAge(int age) { this->age = age; }
void Patient::setName(string name){ this->name = name; }
void Patient::setAddress(string address) { this->address = address; }
void Patient::setContact(string contact) { this->contact = contact; }
void Patient::setIllness(string illness) { this->illness = illness; }
void Patient::setDoctorName(string doctor_name) { doctor_name = doctor_name; }
void Patient::setInsurance(bool insurance) { this->insurance = insurance; }
void Patient::setMedicine(string medicine) { this->medicine = medicine; }

void Patient::print() {
	printf("%-20s|%-20s\n", name.c_str(), address.c_str());
}

void Patient::printDetail() {

}

std::string Patient::toString() {
	string result = to_string(id) + ";" + to_string(age) + ";" + name + ";" + address + ";" + contact + ";" +
		illness + ";" + to_string(insurance) + ";" + doctor_name + ";" + medicine;

	return result;
}


bool Patient::operator <(Node& tmp) {
	Patient p = dynamic_cast<Patient&>(tmp);
	return this->id < p.id;
}
