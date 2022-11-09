#include <iostream>
#include <string>

using namespace std;

int main() {
	string mainStr, subStr;
	int main, sub, flag=0, j, position;
	
	cout << "Enter any string first :: ";
	getline(cin >> ws, mainStr);
	
	cout << "Enter Substring u want to search :: ";
	getline(cin >> ws, subStr);
	
	main = mainStr.length();
	sub = subStr.length();
	
	for(int i=0; i<main; ++i) {
		
		if(mainStr[i] == subStr[0]) {
			
			for(j=0; j<sub; ++j) {
				
				if(mainStr[i+j] == subStr[j])
					flag = 1;	
				else
					flag = 0;
			}
		}	
		if(flag == 1) {
			position = i;
			break;
		}
	}
	
	if(flag == 1) 
		cout << "The substring [ " << subStr << " ] is present in given string at position [ " << position+1 << " ]";
	
	else 
		cout << "The substring is not present in given string";
	
}


