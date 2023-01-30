#include <iostream>

using namespace std;

class CoffeeMachine {
	public:
		CoffeeMachine(): coffeeAmount{0}{
		}
		
		void addCoffee(int amount) {
			coffeeAmount += amount;
		}
		
	protected:
		int coffeeAmount;
};

class LatteMachine: public CoffeeMachine {
	private:
		int milkAmount;
		
	public:
		LatteMachine(): CoffeeMachine{}, milkAmount{0}{
		}
		
		void addMilk(int amount) {
			milkAmount += amount;
		}
		
		int makeLatte(int amount) {
			if(coffeeAmount >= amount && milkAmount >= amount){
				coffeeAmount -= amount;
				milkAmount -= amount;
				
				return 0;
			}
			
			else if(coffeeAmount < amount){
				return -1;	
			}
			
			else if(milkAmount < amount){
				return -2;
			}
		}
};

class FilterCoffeeMachine: public CoffeeMachine {
	public:
		int makeFilterCoffee(int amount) {
			if(coffeeAmount >= amount){
				coffeeAmount -= amount;
				return 0;
			}
				
			else {
				return -1;
			}
		}
};

int main() {
	string chs;
	int coffeeAmnt;
	int materialAmnt;
	
	FilterCoffeeMachine filter;
	LatteMachine latte;
	
	
	while(1) {
		cout << "Filter or latte? ";
		cin >> chs;
		
		if(chs == "filter") {
			cout << "How many cups of coffee do you want? ";
			cin >> coffeeAmnt;
			
			if(filter.makeFilterCoffee(coffeeAmnt) == 0){
				cout << "Enjoy!" << endl << endl;
			}
			
			else {
				while(filter.makeFilterCoffee(coffeeAmnt) == -1){
					cout << "Not enough coffee! Add: ";
					cin >> materialAmnt;
					filter.addCoffee(materialAmnt);
				}
				
				cout << "Enjoy!" << endl << endl;
			}		
		}	
		
		else if(chs == "latte") {
			cout << "How many cups of coffee do you want? ";
			cin >> coffeeAmnt;
			
			if(latte.makeLatte(coffeeAmnt) == 0) {
				cout << "Enjoy!" << endl << endl;
			}
			
			else{
				while(1) {
					if(latte.makeLatte(coffeeAmnt) == -1) {
						cout << "Not enough coffee! Add: ";
						cin >> materialAmnt;
						latte.addCoffee(materialAmnt);
						
						if(latte.makeLatte(coffeeAmnt) == 0){
							break;
						}
					}
					
					if(latte.makeLatte(coffeeAmnt) == -2) {
						cout << "Not enough milk! Add: ";
						cin >> materialAmnt;
						latte.addMilk(materialAmnt);
						
						if(latte.makeLatte(coffeeAmnt) == 0){
							break;
						}
					}
				}
				
				cout << "Enjoy!" << endl << endl;
			}
		}
		
		else if(chs == "none"){
			cout << "Goodbye!";
			break;
		}
	}
}
