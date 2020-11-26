#include "HTMLExportationModule.h"

HTMLExportationModule::HTMLExportationModule(List* dl, List* pl, List* gl, List* ml, List* paymentl) 
	:doctorList(dl), patientList(pl), guardianList(gl), medicineList(ml), paymentList(paymentl)
{}


void HTMLExportationModule::printMainMenu() {
	using namespace std;
	string line(50, '-');

	cout << line << endl;
	cout << "Data Exportation Module" << endl;
	cout << line << endl;
	cout << "1 -> Export Patient Data" << endl;
	cout << "2 -> Export Guardian Data" << endl;
	cout << "3 -> Export Doctor Data" << endl;
	cout << "4 -> Export Medicine Data" << endl;
	cout << "5 -> Export Payment Data" << endl;
	cout << "6 -> Return to Main Menu" << endl;
	cout << line << endl;
}


void HTMLExportationModule::mainProcess(int input){
	switch (input) {
	case 1:
		exportPatient();
		break;
	case 2:
		exportGuardian();
		break;
	case 3:
		exportDoctor();
		break;
	case 4:
		exportMedicine();
		break;
	case 5:
		exportPayment();
		break;
	case 6:
		std::cout << "Returning to Main Menu." << std::endl;
		this->endProcess();
		break;
	default:
		std::cout << "Invalid option! Please try again!" << std::endl;
	}
}


bool HTMLExportationModule::exportPatient(){
	bool status = true;

	try {
		ofstream f("patient.html");
		if (f) {
			f << this->htmlStart;
			f << "<tr><th>Id</th><th>Name</th><th>Age</th><th>Address</th><th>Contact</th><th>Illness</th><th>Insurance</th><th>Medicine</th></tr>";
			Node* ptr = patientList->getHead();
			while (ptr != nullptr) {
				Patient* g = dynamic_cast<Patient*>(ptr);
				printf("<tr><td>%d</td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>",
					g->getId(), g->getName().c_str(), g->getAge(), g->getAddress().c_str(), g->getContact().c_str()
				,g->getIllness().c_str(),to_string(g->getInsurance()).c_str(),g->getMedicine().c_str());
				ptr = ptr->getNext();
			}
			f << this->htmlEnd;
		}
		else {
			throw std::string("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}
	return status;
}


bool HTMLExportationModule::exportGuardian(){
	bool status = true;

	try {
		ofstream f("guardian.html");
		if (f) {
			f << this->htmlStart;
			f << "<tr><th>Id</th><th>Name</th><th>Age</th><th>Gender</th><th>Address</th><th>Contact</th></tr>";
			Node* ptr = guardianList->getHead();
			while (ptr != nullptr) {
				Guardian* g = dynamic_cast<Guardian*>(ptr);
				printf("<tr><td>%d</td><td>%s</td><td>%d</td><td>%c</td><td>%s</td><td>%s</td></tr>",
					g->getId(), g->getName().c_str(), g->getAge(), g->getGender(), g->getAddress().c_str(), g->getContact().c_str());
				ptr = ptr->getNext();
			}
			f << this->htmlEnd;
		}
		else {
			throw std::string("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}
	return status;
}


bool HTMLExportationModule::exportMedicine(){
	bool status = true;

	try {
		ofstream f("medicine.html");
		if (f) {
			f << this->htmlStart;
			f << "<tr><th>Id</th><th>Name</th><th>Price</th></tr>";
			Node* ptr = medicineList->getHead();
			while (ptr != nullptr) {
				Medicine* g = dynamic_cast<Medicine*>(ptr);
				printf("<tr><td>%d</td><td>%s</td><td>%.2f</td></tr>",
					g->getId(), g->getName().c_str(), g->getPrice());
				ptr = ptr->getNext();
			}
			f << this->htmlEnd;
		}
		else {
			throw std::string("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}
	return status;
}

bool HTMLExportationModule::exportDoctor(){
	bool status = true;

	try {
		ofstream f("doctor.html");
		if (f) {
			f << this->htmlStart;
			f << "<tr><th>Id</th><th>Name</th><th>Age</th><th>Gender</th><th>Experienced Field</th>";
			f << "<th>Experienced Year</th><th>Consultation Price</th><th>Consultation Extension</th>";
			f << "<th>Monthly Salary</th></tr>";

			Node* ptr = doctorList->getHead();
			while (ptr != nullptr) {
				Doctor* g = dynamic_cast<Doctor*>(ptr);
				printf("<tr><td>%d</td><td>%s</td><td>%d</td><td>%c</td><td>%s</td><td>%04d</td><td>%.2f</td><td>%d</td><td>%.2f</td></tr>",
					g->getId(), 
					g->getName().c_str(), 
					g->getAge(), 
					g->getGender(), 
					g->getExperience_field().c_str(), 
					g->getExperience_year(),
					g->getConsultation_price(),
					g->getConsultant_extension(),
					g->getMonthly_salary()
				);
				ptr = ptr->getNext();
			}
			f << this->htmlEnd;
		}
		else {
			throw std::string("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}
	return status;
}


bool HTMLExportationModule::exportPayment(){
	bool status = true;

	try {
		ofstream f("payment.html");
		if (f) {
			f << this->htmlStart;
			f << "<tr><th>Id</th><th>Patient Name</th><th>Date</th><th>Total Price</th></tr>";
			Node* ptr = paymentList->getHead();
			while (ptr != nullptr) {
				Payment* g = dynamic_cast<Payment*>(ptr);
				printf("<tr><td>%d</td><td>%s</td><td>%s</td><td>%.2f</td></tr>",
					g->getId(), g->getPatientName().c_str(), g->getDate().c_str(), g->getTotalPrice());
				ptr = ptr->getNext();
			}
			f << this->htmlEnd;
		}
		else {
			throw std::string("Failed to open the patient data file");
		}
		f.close();
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		status = false;
	}
	return status;
}