#include <iostream>
#include <vector>

using namespace std;

struct course
{
	string code;
	float grade;
};

int main() {
	//to control that users want to add new courses
	string addCourse = "y";
	//these are created to getting variables from user, and coppy to vector
	course Course;
	string code; 
	float grade;
	//vector size
	int size = 0;
	//CGPA
	float cgpa = 0;
	
	vector <course> vecCourse;
	
	//get course codes and grades from user, and add vector these 
	while(addCourse == "y") {
		vecCourse.resize(size);
		size += 1;
		
		cout << "Enter course code and grade: ";
		cin >> Course.code;
		cin >> Course.grade;
		
		vecCourse.push_back(Course);
		
		cout << "Add new course? ";
		cin >> addCourse;
	}
	
	//display course codes and grades, and cumulative grade of the student
	cout << endl << "List of entered " << size << " courses:";
	for(int i=0; i<vecCourse.size(); ++i) {
		cout << endl << "- " << vecCourse[i].code << ", Grade: " << vecCourse[i].grade;
		cgpa += vecCourse[i].grade / (size * 1.0);
	}
	
	cout << endl << "CGPA: " << cgpa;
	
	
	vecCourse.clear();
	
}
