#include <iostream>

using namespace std;

int main() {
	//length: number of letters
	int length;
	
	cout << "How many numbers letters are you going to enter? ";
	cin >> length;
	
	char *letter = new char[length];
	int *numOfLetter = new int[length];
	
	for(int i=0; i<length; ++i) {
		cout << "Enter letter and how many times it will be repeated: ";
		cin >> letter[i];
		cin >> numOfLetter[i];
	}
	
	for(int i=0; i<length; ++i) {
		for(int j=0; j<numOfLetter[i]; ++j) {
			cout << letter[i];
		}
	}
	
	delete [] letter;
	delete [] numOfLetter;
}
