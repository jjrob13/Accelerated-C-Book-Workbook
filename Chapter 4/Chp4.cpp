
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::string;
using std::max;
using std::streamsize;
using std::cin;
using std::cout;
using std::setprecision;
using std::endl;
using std::domain_error;
using std::sort;

void gradesProgram(){
	//1. read all student info
	Student_info record;
	vector<Student_info> students;

	//tracks longest student name
	string::size_type maxLen = 0;

	//INV:
	//students has all student records read so far
	//maxLen contains the longest student name read so far.
	while(read_student_record(cin, record)){
		//add to vector
		students.push_back(record);

		//update maxLen
		maxLen = max(maxLen, record.name.size());
	}

	//2. sort vector of students
	sort(students.begin(), students.end(), compare);

	//3. print all student grades
	string::size_type padding = 5;
	//INV: i student records have been printed so far
	for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
		try{
				double finalGrade = grade(students[i]);
				streamsize prec = cout.precision();
				cout << students[i].name << string(maxLen - students[i].name.size() + padding, ' ') << setprecision(3)
				<< finalGrade << setprecision(prec) << endl;
			}catch(domain_error e){
				cout << e.what() << endl;
			}
	}
}

int main(){

	return 0;
}
