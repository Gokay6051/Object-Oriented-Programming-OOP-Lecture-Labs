#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName, sentence, chc; //chc is users choice (y or n)
	ofstream openFile;  //head of the open and write on the file
	string readLine;
	
	cout << "Enter file name: ";
	getline(cin >> ws, fileName);
	
	openFile.open(fileName.c_str());
	
	cout << "Enter information to store.." << endl;
	getline(cin >> ws, sentence);
	openFile << sentence << endl;
	
	cout << "Want to enter more ? : (y/n).. ";
	cin >> chc;
		
	while(chc != "n") {
		getline(cin >> ws, sentence);
		openFile << sentence << endl;
		cout << "Want to enter more ? : (y/n).. ";
		cin >> chc;
	}
	
	openFile.close(); //finish of the open and write on the file
	
	cout << endl << "The information successfully stored in the file..!!" << endl << endl;
	
	cout << "Want to see ? (y/n).. ";
	cin >> chc;
	
	if(chc == "y") {
		cout << "The file contains:" << endl;
		
		ifstream readFile;  
		readFile.open(fileName.c_str());
		
		while(getline(readFile, readLine)) {
			cout << readLine << endl;
		}
		
		
		readFile.close();
	}
	
	
	
	
	
}
