#include <iostream>

using namespace std;

struct NUMBERLIST {
	int intArr[10];	
	string str;
};

void addUpPtr(NUMBERLIST *numberList);

int main() {
	NUMBERLIST numberList;
	
	cout << "Enter 10 integers and order of summation: ";
	
	for(int i=0; i<10; ++i) {
		cin >> numberList.intArr[i];
	}
	
	cin >> numberList.str;
	
	addUpPtr(&numberList);
	
	for(int i=0; i<10; ++i) {
		cout << numberList.intArr[i] << " ";
	}
}

void addUpPtr(NUMBERLIST *numberList) {
	if((*numberList).str == "left-to-right") {
		for(int i=0; i<9; ++i) {
			(*numberList).intArr[i+1] += (*numberList).intArr[i];
		}
	}
	
	else if((*numberList).str == "right-to-left") {
		for(int i=9; i>0; --i) {
			(*numberList).intArr[i-1] += (*numberList).intArr[i];
		}
	}
}
