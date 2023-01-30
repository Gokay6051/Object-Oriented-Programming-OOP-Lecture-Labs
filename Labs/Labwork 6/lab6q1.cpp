#include <iostream>

using namespace std;

class UpDownNumbers{
	private:
		int start;
		int length;
		int *numbers;
		
	public:
		void setStart(int start){
			this->start = start;
			generate();
		}
		
		int getStart() {
			return start;
		}
		
		int getLength() {
			return length;
		}
		
		UpDownNumbers(int start, int length): start{start}, length{length} {
			numbers = new int[length];
			generate();
		}
		
		UpDownNumbers(const UpDownNumbers &a) {
			start = a.start;
			length = a.length;
			numbers = new int[a.length];
			generate();
		}
		
		~UpDownNumbers() {
			delete [] this->numbers;
		}
		
		void generate() {
			numbers[0] = start;
			for(int i=1; i<length; ++i) {
				if(numbers[i-1] % 2 == 0){
					numbers[i] = numbers[i-1] / 2 + 5; 
				}
				else{
					numbers[i] = 3 * numbers[i-1] - 1;
				} 
			} 
		}
		
		void print() {			
			for(int i=0; i<length; ++i) {
				cout << numbers[i] << " ";
			}
		}
};

int main() {
	int start, length;
	
	cout << "Enter length and start for Object A: ";
	cin >> length >> start;
	
	UpDownNumbers a(start, length);
	UpDownNumbers b = a;
	
	cout << "Object A (start: " << a.getStart() << ", length: " << a.getLength() << "): ";
	a.print();
	cout << endl << "Object B (b = a): ";
	b.print();
	cout << endl;
	
	cout << "Enter new start for Object B: ";
	cin >> start;
	b.setStart(start);
	cout << "b.start is " << start << " now" << endl;
	
	cout << "Object A (start: " << a.getStart() << ", length: " << a.getLength() << "): ";
	a.print();
	cout << endl << "Object B (start: " << b.getStart() << ", length: " << b.getLength() << "): ";
	b.print();
	
}
