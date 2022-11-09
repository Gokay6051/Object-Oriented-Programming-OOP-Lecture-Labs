#include <iostream>
#include <string>

using namespace std;

int main() {
	string line;
	int vowel=0, conso=0, digit=0, space=0; 
	char ch;
	
	cout << "Enter a line of string: ";
	getline(cin >> ws, line);
	
	for(int i=0; i<line.length(); ++i) {
		if(isalpha(line[i])) { //to is vowel or is consonants
			ch = toupper(line[i]);
			
			if(ch=='A' || ch=='E' || ch=='I' ||	ch=='O' || ch=='U')
				++vowel;
			else
				++conso;
		}
		
		else if(isdigit(line[i])) //to is digit
			++digit;
			
		else if(isblank(line[i])) //to is blank
			++space;
	}
	
	
	cout << "Vowels: " << vowel << endl;
	cout << "Consonants: " << conso << endl;
	cout << "Digits: " << digit << endl;
	cout << "Blanks: " << space << endl;
	
}
