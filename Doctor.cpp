#include "Doctor.h"

void Doctor::print() {
	printf("%-20s|%-20s\n", name.c_str(), experience_field.c_str());
}

void Doctor::printDetail() {
	string line(50, '-');

	cout << line << endl;
	cout << "Doctor ID : " << id << endl;
	cout << "Doctor Name : " << name << endl;
	cout << "Gender : " << gender << endl;
	cout << "Age : " << age << endl;
	cout << "Experienced Field : " << experience_field << endl;
	cout << "Experienced Year : " << experience_year << endl;
	cout << "Monthly Salary : " << monthly_salary << endl;
	cout << "Consultation Price : " << consultation_price << endl;
	cout << "Consultation Extension : " << consultant_extension << endl;
	cout << line << endl;
}

std::string Doctor::toString() {
	return to_string(id) + ";" + name + ";" + to_string(age) + ";" + gender +
		";" + to_string(experience_year) + ";" + experience_field + ";" +
		to_string(consultant_extension) +
		";" + to_string(consultation_price) + ";" + to_string(monthly_salary);
}


bool Doctor::operator <(Node& tmp) {
	Doctor d = dynamic_cast<Doctor&>(tmp);
	return this->id < d.id;
}


/*constructor
* get input of age, experience year, consultant extension, monthly salary, consultation price, name, experience field, gender
*/
Doctor::Doctor(int id, string name, int age, char  gender, int  experience_year, string  experience_field, int  consultant_extension, double  consultation_price, double  monthly_salary)
{
	this->setId(id);
	this->setName(name);
	this->setAge(age);
	this->setGender(gender);
	this->setExperience_year(experience_year);
	this->setExperience_field(experience_field);
	this->setConsultant_extension(consultant_extension);
	this->setConsultation_price(consultation_price);
	this->setMonthly_salary(monthly_salary);
}


int Doctor::getId() { return id; }
string Doctor::getName() { return name; }
int Doctor::getAge() { return age; }
char Doctor::getGender() { return gender; }
int Doctor::getExperience_year() { return experience_year; }
string Doctor::getExperience_field() { return experience_field; }
int Doctor::getConsultant_extension() { return consultant_extension; }
double Doctor::getConsultation_price() { return consultation_price; }
double Doctor::getMonthly_salary() { return monthly_salary; }


void Doctor::setId(int a) { this->id = a; }
void Doctor::setName(string a) { this->name = a; }
void Doctor::setAge(int a) { this->age = a; }
void Doctor::setGender(char a) { this->gender = a; }
void Doctor::setExperience_year(int a) { this->experience_year = a; }
void Doctor::setExperience_field(string a) { this->experience_field = a; }
void Doctor::setConsultant_extension(int a) { this->consultant_extension = a; }
void Doctor::setConsultation_price(double a) { this->consultation_price = a; }
void Doctor::setMonthly_salary(double a) { this->monthly_salary = a; }
