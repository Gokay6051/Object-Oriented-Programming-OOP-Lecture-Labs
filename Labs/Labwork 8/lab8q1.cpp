#include <iostream>

using namespace std;

class calculator {
	private: 
		float* numbers;
		int length;
		
	public:
		calculator(): calculator(0) {
		}
		
		calculator(int size): length{size}{
			numbers = new float(length);
		}
		
		~calculator() {
			delete[] numbers;
		}
		
		calculator operator +(const calculator &obj) {
			calculator temp(length);
			for(int i=0; i<length; ++i) {
				temp.numbers[i] = numbers[i] + obj.numbers[i];
			}
			return temp;
		}
		
		calculator operator -(const calculator &obj) {
			calculator temp(length);
			for(int i=0; i<length; ++i) {
				temp.numbers[i] = numbers[i] - obj.numbers[i];
			}
			return temp;
		}
		
		calculator operator *(const calculator &obj) {
			calculator temp(length);
			for(int i=0; i<length; ++i) {
				temp.numbers[i] = numbers[i] * obj.numbers[i];
			}
			return temp;
		}
		
		calculator operator /(const calculator &obj) {
			calculator temp(length);
			for(int i=0; i<length; ++i) {
				temp.numbers[i] = numbers[i] / obj.numbers[i];
			}
			return temp;
		}
		
		calculator& operator =(const calculator &obj) {
			length = obj.length;
			for(int i=0; i<length; ++i) {
				numbers[i] = obj.numbers[i];
			}
			
		}
		
		void getNumbers() {
			for(int i=0; i<length; ++i) {
				cin >> numbers[i];
			}
		}
		
		int getLength() {
			return this->length;
		}
		
		friend ostream &operator<<(ostream &os, const calculator &obj);
};


int main() {
	int length;
	string chs;
	calculator obj3;
	
	
	cout << "Length of the first number set: ";
	cin >> length;
	
	
	calculator obj1(length);
	obj1.getNumbers();
	cout << "First set entered: ";
	cout << obj1;
	
	cout << endl << "Length of the second number set: ";
	cin >> length;
	
	calculator obj2(length);
	obj2.getNumbers();
	cout << "Second set entered: ";
	cout << obj2;
	
	while(1) {
		cout << endl << "Choose operation: ";
		cin >> chs;
		
		if (chs == "exit") {
			break;
		}
		
		else if (chs == "+") {
			obj3 = obj1+obj2;
			cout << obj3;
		}
		
		else if(chs == "-") {
			obj3 = obj1-obj2;
			cout << obj3;
		}
		
		else if (chs == "*") {
			obj3 = obj1*obj2;
			cout << obj3;
		}
		
		else if (chs == "/") {
			obj3 = obj1/obj2;
			cout << obj3;
		}
		
	}
	
}

ostream &operator<<(ostream &os, const calculator &obj)
{
	for(int i=0; i<obj.length; ++i) {
		os << obj.numbers[i] << " ";
	}
	
    return os;
}
