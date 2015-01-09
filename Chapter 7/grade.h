#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"
#include <list>
#include <iostream>
#include <map>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);
double grade_with_average(const Student_info &);

bool failingStudent(const Student_info &);
bool did_all_hw(const Student_info &);

void write_grade_analysis(std::ostream &, const std::vector<Student_info> &, const std::vector<Student_info> &);

std::vector<Student_info> extract_fails(std::vector<Student_info> &);
std::list<Student_info> extract_fails(std::list<Student_info> &);

std::vector<Student_info> extract(bool(const Student_info &), std::vector<Student_info> &);

std::map<std::string, int> get_grade_distribution(const std::vector<Student_info> &);

#endif
