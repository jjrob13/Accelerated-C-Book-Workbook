//This is a comment in Chapter 4
//Can I see this after linking? that would be cool
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>
#include <iostream>

struct Student_info{
	std::string name;
	double midterm;
	double final;
	std::vector<double> hw;
};

bool compare(const Student_info &, const Student_info &);

std::istream & read_student_record(std::istream &, Student_info &);

#endif