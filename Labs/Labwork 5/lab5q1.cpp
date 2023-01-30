#include <iostream>
#include <iomanip>

using namespace std;

class Course{
	private:
		int mtG;
		int hwG;
		int finG;
		double mtW;
		double hwW;
		double finW;
		string name;
		string letterGrade;
		
	public:
		Course(): Course(0.3, 0.2, 0.5){
		}
		
		Course(double mtW, double hwW, double finW): mtW{mtW}, hwW{hwW}, finW{finW} {
		} 
		
		void calculate() {
			if((mtW*mtG + hwW*hwG + finW*finG) <= 100 && (mtW*mtG + hwW*hwG + finW*finG) > 90)	
				letterGrade = "AA";
			
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 90 && (mtW*mtG + hwW*hwG + finW*finG) > 85)	
				letterGrade = "BA";
			
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 85 && (mtW*mtG + hwW*hwG + finW*finG) > 80)	
				letterGrade = "BB";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 80 && (mtW*mtG + hwW*hwG + finW*finG) > 70)	
				letterGrade = "CB";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 70 && (mtW*mtG + hwW*hwG + finW*finG) > 60)	
				letterGrade = "CC";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 60 && (mtW*mtG + hwW*hwG + finW*finG) > 50)	
				letterGrade = "DC";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 50 && (mtW*mtG + hwW*hwG + finW*finG) > 45)	
				letterGrade = "DD";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 45 && (mtW*mtG + hwW*hwG + finW*finG) > 35)	
				letterGrade = "FD";
				
			else if((mtW*mtG + hwW*hwG + finW*finG) <= 35 && (mtW*mtG + hwW*hwG + finW*finG) >= 0)	
				letterGrade = "FF";
		}
		
		void setMidterm(int mtG){
			this->mtG = mtG;
		}
		int getMidterm(){
			return mtG;
		}
		
		void setHomework(int hwG){
			this->hwG = hwG;
		}
		int getHomework(){
			return hwG;
		}
		
		void setFinal(int finG){
			this->finG = finG;
		}
		int getFinal(){
			return finG;
		}
		
		void setName(string name){
			this->name = name;
		}
		string getName(){
			return name;
		}
		
		string getGrade() {
			calculate();
			return letterGrade;
		}
};

int main() {
	int mtG;
	int hwG;
	int finG;
	double mtW;
	double hwW;
	double finW;
	string name;
	
	cout << "Enter weights for second course: ";
	cin >> mtW;
	cin >> hwW;
	cin >> finW;
	
	Course first;
	Course second(mtW, hwW, finW);
	
	//to first courses variables
	cout << "Enter first course name: ";
	cin >> name;
	cout << "Enter first course grades: ";
	cin >> mtG;
	cin >> hwG;
	cin >> finG;
	
	first.setName(name);
	first.setMidterm(mtG);
	first.setHomework(hwG);
	first.setFinal(finG);
	
	//to second courses variables
	cout << "Enter second course name: ";
	cin >> name;
	cout << "Enter second course grades: ";
	cin >> mtG;
	cin >> hwG;
	cin >> finG;
	
	second.setName(name);
	second.setMidterm(mtG);
	second.setHomework(hwG);
	second.setFinal(finG);
	
	cout << "Course" << setw(4) << "Midterm" << setw(4) << "Homework" << setw(4) << "Final" << setw(4) << "Letter" << endl;
	cout << first.getName() << setw(4) << first.getMidterm() << setw(9) << first.getHomework() << setw(10) << first.getFinal() << setw(7) << first.getGrade() << endl;
	cout << second.getName() << setw(4) << second.getMidterm() << setw(9) << second.getHomework() << setw(10) << second.getFinal() << setw(7) << second.getGrade();
	
}
