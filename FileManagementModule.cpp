#include "FileManagementModule.h"


FileManagementModule::FileManagementModule(List* dl, List* pl, List* gl, List* ml, List* paymentl, int mode)
	: doctorList(dl), patientList(pl), guardianList(gl), medicineList(ml), paymentList(paymentl)
{
	bool status = true;

	try {
		switch (mode) {
		case READMODE:
		{
			status = loadPatient();
			if (!status) throw "Failed to load patient data";
			status = loadGuardian();
			if (!status) throw "Failed to load guardian data";
			status = loadMedicine();
			if (!status) throw "Failed to load medicine data";
			status = loadDoctor();
			if (!status) throw "Failed to load doctor data";
			status = loadPayment();
			if (!status) throw "Failed to load payment data";
		}
		case WRITEMODE:
		{
			status = savePatient();
			if (!status) throw "Failed to save patient data";
			status = saveGuardian();
			if (!status) throw "Failed to save guardian data";
			status = saveMedicine();
			if (!status) throw "Failed to save medicine data";
			status = saveDoctor();
			if (!status) throw "Failed to save doctor data";
			status = savePayment();
			if (!status) throw "Failed to save payment data";
		}
		}
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
	}
}

bool FileManagementModule::savePatient() {
	bool status = true;
	try {
		std::ofstream f("patient.dat", std::ios::binary);
		if (f) {
			f << patientList->size() << std::endl;
			if (!patientList->isEmpty()) {
				Node* tmp = patientList->getHead();
				while (tmp != nullptr) {
					f << tmp->toString() << std::endl;
					tmp = tmp->getNext();
				}
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::saveGuardian() {
	bool status = true;
	try {
		std::ofstream f("guardian.dat", std::ios::binary);
		if (f) {
			f << guardianList->size() << std::endl;
			if (!guardianList->isEmpty()) {
				Node* tmp = guardianList->getHead();
				while (tmp != nullptr) {
					f << tmp->toString() << std::endl;
					tmp = tmp->getNext();
				}
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::saveMedicine() {
	bool status = true;
	try {
		std::ofstream f("medicine.dat", std::ios::binary);
		if (f) {
			f << medicineList->size() << std::endl;
			if (!medicineList->isEmpty()) {
				Node* tmp = medicineList->getHead();
				while (tmp != nullptr) {
					f << tmp->toString() << std::endl;
					tmp = tmp->getNext();
				}
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::saveDoctor() {
	bool status = true;
	try {
		std::ofstream f("doctor.dat", std::ios::binary);
		if (f) {
			f << doctorList->size() << std::endl;
			if (!doctorList->isEmpty()) {
				Node* tmp = doctorList->getHead();
				while (tmp != nullptr) {
					f << tmp->toString() << std::endl;
					tmp = tmp->getNext();
				}
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::savePayment() {
	bool status = true;
	try {
		std::ofstream f("payment.dat", std::ios::binary);
		if (f) {
			f << paymentList->size() << std::endl;
			if (!paymentList->isEmpty()) {
				Node* tmp = paymentList->getHead();
				while (tmp != nullptr) {
					f << tmp->toString() << std::endl;
					tmp = tmp->getNext();
				}
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::loadPatient() {
	bool status = true;
	std::string input = "";

	try {
		std::ifstream f("patient.dat", std::ios::binary);
		if (f) {
			while (!f.eof()) {
				f >> input;
				std::queue<std::string> part = InputModule::split_string(input);
				if (part.size() != 9) {
					throw "Input Mismatch Exception";
				}
				int id = std::stoi(part.front());
				part.pop();
				int age = std::stoi(part.front());
				part.pop();
				std::string name = part.front();
				part.pop();
				std::string address = part.front();
				part.pop();
				std::string contact = part.front();
				part.pop();
				std::string illness = part.front();
				part.pop();
				bool insurance = static_cast<bool>(std::stoi(part.front()));
				part.pop();
				std::string doctor_name = part.front();
				part.pop();
				std::string medicine = part.front();

				Node* n = new Patient(id, age, name, address, contact, illness, insurance, doctor_name, medicine);
				patientList->add(n);
			}
		}
		else {
			throw("Failed to open the patient data file");
		}
		patientList->sort();
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::loadGuardian() {
	bool status = true;
	std::string input = "";

	try {
		std::ifstream f("guardian.dat", std::ios::binary);
		if (f) {
			while (!f.eof()) {
				f >> input;
				std::queue<std::string> part = InputModule::split_string(input);
				if (part.size() != 6)
					throw "Input Mismatch Exception";
				int id = std::stoi(part.front());
				part.pop();
				int age = std::stoi(part.front());
				part.pop();
				std::string name = part.front();
				part.pop();
				std::string address = part.front();
				part.pop();
				std::string contact = part.front();
				part.pop();
				char gender = part.front().at(0);
				Node* n = new Guardian(id, age, name, address, contact, gender);
				guardianList->add(n);
			}
		}
		else {
			throw("Failed to open the guardian data file");
		}
		guardianList->sort();
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::loadMedicine() {
	bool status = true;
	std::string input = "";

	try {
		std::ifstream f("medicine.dat", std::ios::binary);
		if (f) {
			while (!f.eof()) {
				f >> input;
				std::queue<std::string> part = InputModule::split_string(input);
				if (part.size() != 3)
					throw "Input Mismatch Exception";
				int id = std::stoi(part.front());
				part.pop();
				std::string name = part.front();
				part.pop();
				double price = std::stod(part.front());
				
				Node* n = new Medicine(id, name, price);
				medicineList->add(n);
			}
		}
		else {
			throw("Failed to open the medicine data file");
		}
		medicineList->sort();
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}


bool FileManagementModule::loadDoctor() {
	bool status = true;
	std::string input = "";

	try {
		std::ifstream f("doctor.dat", std::ios::binary);
		if (f) {
			while (!f.eof()) {
				f >> input;
				std::queue<std::string> part = InputModule::split_string(input);
				if (part.size() != 9)
					throw "Input Mismatch Exception";

				int id = std::stoi(part.front());
				part.pop();
				std::string name = part.front();
				part.pop();
				int age = std::stoi(part.front());
				part.pop();
				char gender = part.front().at(0);
				part.pop();
				int experience_year = std::stoi(part.front());
				part.pop();
				std::string experience_field = part.front();
				part.pop();
				int consultant_extension = std::stoi(part.front());
				part.pop();
				double consultation_price = std::stod(part.front());
				part.pop();
				double monthly_salary = std::stod(part.front());

				Node* n = new Doctor(id, name, age, gender, experience_year, experience_field, consultant_extension, consultation_price, monthly_salary);
				doctorList->add(n);
			}
		}
		else {
			throw("Failed to open the doctor data file");
		}
		doctorList->sort();
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}

bool FileManagementModule::loadPayment() {
	bool status = true;
	std::string input = "";

	try {
		std::ifstream f("payment.dat", std::ios::binary);
		if (f) {
			while (!f.eof()) {
				f >> input;
				std::queue<std::string> part = InputModule::split_string(input);
				if (part.size() != 4)
					throw "Input Mismatch Exception";
				int id = std::stoi(part.front());
				part.pop();
				std::string patient_name = part.front();
				part.pop();
				std::string date = part.front();
				part.pop();
				double totalPrice = std::stod(part.front());

				Node* n = new Payment(id, patient_name, date, totalPrice);
				paymentList->add(n);
			}
		}
		else {
			throw("Failed to open the payment data file");
		}
		paymentList->sort();
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}

	return status;
}