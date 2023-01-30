#include <iostream>
#include <cstdlib>

using namespace std;

class NumbersClass {
	private: 
		int *numbers;
		int length;
		
		bool isPrime(int num) {
			if(num <= 1) return false;
				
			for(int i=2; i<num/2; ++i) {
				if(num % i == 0) return false;
			}
				
			return true;
		}
		
	public:
		NumbersClass(): NumbersClass(0) {}
		 
		NumbersClass(int length): length{length} {
			numbers = new int[length];
			generate();
		}
		
		NumbersClass(const NumbersClass &a) {
			length = a.length;
			numbers = new int[length];
			
			for(int i=0; i<length; ++i) {
				numbers[i] = a.numbers[i];
			}
		}
		
		~NumbersClass() {
			delete [] this->numbers;
		}
		
		void generate() {
			for(int i=0; i<length; ++i) {
				numbers[i] = rand();
			}
		}
		
		void filter(string str) {
			if(str == "prime"){
				for(int i=0; i<length; ++i){
					if(isPrime(numbers[i]) == false){
						numbers[i] = -1;
					}
				}
			}
			
			else if(str == "nonprime") {
				for(int i=0; i<length; ++i){
					if(isPrime(numbers[i]) == true){
						numbers[i] = -1;
					}
				}
			}
			
			
		}
		
		void print() {
			for(int i=0; i<length; ++i) {
				if(numbers[i] != -1){
					cout << numbers[i] << " ";
				}
			}
		}
};

int main() {
	int length;
	
	cout << "Enter length: ";
	cin >> length;
	
	NumbersClass A(length);
	NumbersClass B = A;
	NumbersClass C = A;

	
	A.print();
	cout << endl;
	
	B.filter("prime");
	B.print();
	cout << endl;
	
	C.filter("nonprime");
	C.print();
}
