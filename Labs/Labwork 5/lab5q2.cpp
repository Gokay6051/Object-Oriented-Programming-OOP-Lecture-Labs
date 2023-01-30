#include <iostream>
#include <iomanip>

using namespace std;

class Contact{
	private: 
		string name;
		string number;
		
	public:
		Contact(): Contact("Unknown", "0"){
		}
		
		Contact(string name, string number): name{name}, number{number}{
		} 
		
		void print(string str) {
			if(str == "light"){
				cout << name << setw(18 - this->name.length()) << number;
			}
			
			else if(str == "header") {
				cout << "Name" << setw(16) << "Number";
			}
		}
		
		void setName(string name) {
			this->name = name;
		}
		string getName(){
			return this->name;
		}
		
		void setNumber(string number) {
			this->number = number;
		}
		string getNumber(){
			return number;
		}
}; 

class AddressBook{
	private:
		int nrofcontacts;
		Contact contacts[30];
		int search(string) {
			
		}
		
	public:
		AddressBook(): nrofcontacts{0}{
		}
		
		bool add(Contact contact) {
			for(int i=0; i<nrofcontacts; ++i) {
				if(contacts[i].getName() == contact.getName()) {
					return false;	
				}
			}
			contacts[nrofcontacts].setName(contact.getName());
			contacts[nrofcontacts].setNumber(contact.getNumber());
			++nrofcontacts;
			return true;
		}
		
		bool remove(string name) {
			for(int i=0; i<nrofcontacts; ++i) {
				if(name == contacts[i].getName()) {
					for(; i<nrofcontacts-1; ++i) {
						contacts[i] = contacts[i+1];
					}
					--nrofcontacts;
					return true;
				}
			}
			return false;
		}
		
		void print() {
			contacts[0].print("header");
			cout << endl;
			
			for(int i=0; i<nrofcontacts; ++i) {
				contacts[i].print("light");
				cout << endl;
			}	
			cout << endl;
		}
		
		void setNrof(int nrofcontacts) {
			this->nrofcontacts = nrofcontacts;
		}
		int getNrof() {
			return nrofcontacts;
		}
		
		
};

int main() {
	//choice
	int chc; //chc {-1}
	
	string name;
	string number;
	//int nrofcontacts {0};
	
	AddressBook addressBook;
	
	while(chc != 4) {
		//menu
		cout << "1. Display Address Book" << endl << "2. Add New Contact" << endl << "3. Remove Contact" << endl << "4. Exit" << endl << "Enter your choice: ";
		cin >> chc;
		
		if(chc == 1) {
			if(addressBook.getNrof() == false)	cout << "No contacts available." << endl << endl;
			
			else {
				addressBook.print();
			}
		}
		
		if(chc == 2) {
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter number: ";
			cin >> number;
			
			if(addressBook.add(Contact(name, number)) == true) {
				cout << "Contact added." << endl << endl;
			}
			else{
				cout << "Contact already exists." << endl << endl;
			}
		}
		
		if(chc == 3) {
			cout << "Enter name: ";
			cin >> name;
			
			if(addressBook.remove(name) == true){
				cout << "Contact removed." << endl << endl;
			}
			
			else{
				cout << "Contact is not available." << endl << endl;
			}
		}
	}
	
	cout << "Goodbye.";
}










