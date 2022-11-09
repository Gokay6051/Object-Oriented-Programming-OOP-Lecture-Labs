#include <iostream> 

using namespace std;
//hangi iþlemler yer alacak?
class Calculator {
	private:
		//num1 and num2 are operands
		int num1;
		int num2;
		//opr: operator
		string opr;
		double result;
		
	public:
		void setNum1(int num1);
		void setNum2(int num2);
		double getResult();
		void run();
};

void Calculator::setNum1(int num1) {
	this->num1 = num1;
}

void Calculator::setNum2(int num2) {
	this->num2 = num2;
}

double Calculator::getResult() {
	result = num1 + num2;
	return result;
}

void Calculator::run() {
	
}


int main() {
	//operands
	int num1, num2;
	//operator
	string opr;
	//garbage value
	string garbg;
	
	Calculator calculator;
	
	cout << "Enter your operation: ";
	cin >> opr;
	cin >> num1;
	cin >> garbg;
	cin >> num2;
	
	calculator.setNum1(num1);
	calculator.setNum2(num2);
	
	cout << calculator.getResult();
}
