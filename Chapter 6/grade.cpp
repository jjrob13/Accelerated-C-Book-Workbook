#include "grade.h"
#include "median.h"
using std::vector;
using std::map;
using std::string;

double grade(double midterm, double final, double hw_avg){
	return midterm * .2 + final * .4 + hw_avg * .4;
}

double grade(double midterm, double final, const vector<double> & hw){
	if(hw.empty())
		return grade(midterm, final, 0);

	return grade(midterm, final, median(hw));
}

double grade(const Student_info & student){
	return grade(student.midterm, student.final, student.hw);
}

string get_grade(const Student_info & student){
	double student_grade = grade(student);

	if(student_grade >= 90){
		static const string A = "A";
		return A;
	}

	if(student_grade >= 80){
		static const string B = "B";
		return B;
	}

	if(student_grade >= 70){
		static const string C = "C";
		return C;
	}

	if(student_grade >= 60){
		static const string D = "D";
		return D;
	}

	static const string F = "F";

	return F;
}

map<string, int> get_grade_distribution(const vector<Student_info> & students){
	map<string, int> result;

	for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
		result[get_grade(*it)]++;
	}

	return result;

}