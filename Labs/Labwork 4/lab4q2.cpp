#include <iostream>
#include <iomanip>

using namespace std;

class Employee {
private:
	string name;
	//employeed years
	int years;
	double salary;
	double bonus;
	
public:	
	void setName(string);
	void setYears(int);
	void setSalary(double);
	
	void calculateBonus();
	void print();
};

void Employee::setName(string name) {
	this->name = name;	
}

void Employee::setYears(int years) {
	this->years = years;
}

void Employee::setSalary(double salary) {
	this->salary = salary;
}

void Employee::calculateBonus() {
	if(this->years <= 5) {
		this->bonus = 0;
	}
	else if(this->years <= 10) {
		this->bonus = this->salary * 0.05;
	}
	else if(this->years <= 15) {
		this->bonus = this->salary * 0.10;
	}
	else if(this->years <= 20) {
		this->bonus = this->salary * 0.15;
	}
	else {
		this->bonus = this->salary * 0.20;
	}
}

void Employee::print() {
	cout << endl << this->name << setw(19-this->name.length()) << this->years << setw(10) << this->salary << setw(10) << this->bonus;
}

int main() {
	//number of inputs
	int n;
	//coppy of Employee class variables
	string name;
	int years;
	double salary;
	
	cout << "How many employees do you have to deal with: ";
	cin >> n;
	
	Employee *employee = new Employee[n];
	
	for(int i=0; i<n; ++i) {
		cout << "Enter employee name, employed years and salary: ";
		cin >> name;
		cin >> years;
		cin >> salary;
		
		employee[i].setName(name);
		employee[i].setYears(years);
		employee[i].setSalary(salary);
		employee[i].calculateBonus();
	}
	
	cout << "Name" << setw(15) << "Years" << setw(10) << "Salary" << setw(10) << "Bonus";
	
	for(int i=0; i<n; ++i) {
		employee[i].print();
	}
}
