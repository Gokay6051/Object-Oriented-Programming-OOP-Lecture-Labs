#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class Villager{
	public:
		Villager(): health{20}, attackPower{0}{
		}
		
		Villager(int health, int power): health{health}, attackPower{power} {
		}
		
		int attack(Villager &villager) {
			return 0;
		}
		
		int getHealth() {
			return this->health;
		}
		
		void setHealth(int health) {
			this->health = health;
		}
		
	protected:
		int health;
		int attackPower;
};

class Archer: public Villager{
	private:
		int nrOfArrows;
		
	public:
		Archer(): Villager{60, 40}, nrOfArrows{5}{
		}
		
		int attack(Villager &villager) {
			if(villager.getHealth() < 0) 
				return -1;
				
			else if(this->nrOfArrows == 0)
				return -2;
				
			else {
				this->nrOfArrows -= 1;
    			return (rand()%(this->attackPower));
			}
		}
		
		int attack(Archer &archer) {
			if(archer.getHealth() < 0) 
				return -1;
				
			else if(this->nrOfArrows == 0)
				return -2;
				
			else {
				this->nrOfArrows -= 1;
    			return (rand()%(this->attackPower));
			}
		}
		
		int getNrOfArrows() {
			return this->nrOfArrows;
		}
};

int main() {
	int demage;	
	Villager *villagers = new Villager[20];
	Archer *archers = new Archer[20];
	
	int i=0;
	int num1, num2;
	string ch1, ch2, garbage;
	
	srand(time(NULL));
	
	while(1) {
		cout << "Enter command #" << i+1 << ": ";
		cin >> ch1 >> num1 >> garbage >> ch2 >> num2;
		
		if(ch1 == ch2 && num1 == num2){
			break;
		}
		
		if(ch1 == "Villager") {
			cout << "Villager" << num1 << " can't attack!" << endl << endl;
		}
		
		else if(ch1 == "Archer" && ch2 == "Villager") {
			demage = archers[num1-1].attack(villagers[num2-1]);
			
			if(demage > 0) {
				cout << "Archer" << num1 << " made " << demage << " damage to " << ch2 << num2 << "." << endl;
				villagers[num2-1].setHealth(villagers[num2-1].getHealth() - demage);
			}
			
			else if(demage == -2) {
				cout << "Archer" << num1 << " is out of arrows!" << endl;
			}
			
			if(villagers[num2-1].getHealth() < 0 || demage == -1) {
				cout << "Villager" << num2 << " died!" << endl;
			}
			
			cout << endl;
		}
		
		else if(ch1 == "Archer" && ch2 == "Archer"){
			demage = archers[num1-1].attack(archers[num2-1]);
			
			if(demage > 0) {
				cout << "Archer" << num1 << " made " << demage << " damage to " << ch2 << num2 << "." << endl;
				archers[num2-1].setHealth(archers[num2-1].getHealth() - demage);
			}
			
			else if(demage == -2) {
				cout << "Archer" << num1 << " is out of arrows!" << endl;
			}
			
			if(archers[num2-1].getHealth() < 0 || demage == -1) {
				cout << "Archer" << num2 << " died!" << endl;
			}
			
			cout << endl;
		}
					
		++i;
	}
	
	delete[] villagers;
	delete[] archers;
} 
