#include <iostream>
#include <iomanip>

using namespace std;

struct cars{
	string car;
	int totalKm;
	int lastKm;
	string needMain;
	cars* next;
};

int main() {
	cars* head;
	cars* Car = new cars();

	head = Car;
	
	//get car variables
	for(int i=0; i<5; ++i) {
		cout << "Enter car model: ";
		cin >> Car->car;
		cout << "Enter total distance: ";
		cin >> Car->totalKm;
		cout << "Enter last km: ";
		cin >> Car->lastKm;
		
		if(Car->totalKm - Car->lastKm > 10000){
			Car->needMain = "YES";
		}
		else {
			Car->needMain = "NO";
		}
		
		Car->next = new cars();
		Car = Car->next;
	}
	Car = NULL;
	Car = head;
	
	cout << endl << "Car" << setw(23) << "Total km" << setw(14) << "Last km" << setw(23) << "Needs Maintance" << endl;
	
	//display the table
	while(Car->next != NULL) {
		cout << Car->car << setw(23-Car->car.length()) << Car->totalKm << setw(14) << Car->lastKm << setw(23) << Car->needMain << endl;
		Car = Car->next;
	}
}
