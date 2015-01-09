#include <vector>
#include <iostream>
#include "Student_info.h"
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>
#include "grade.h"
#include <list>
#include <cctype>
#include "my_string_lib.h"
#include "framelib.h"
#include <sstream>

using std::stringstream;
using std::list;
using std::setw;
using std::max;
using std::string;
using std::cin;		using std::cout;
using std::endl;
using std::vector;
using std::getline;
using std::istream;

void print_student_vector(const vector<Student_info> &);
void print_student_list(const list<Student_info> &);
void student_vector_drive();
void student_list_drive();
void test_my_string_splitter();
void built_in_string_split();
void test_picture_concatenation();
void test_list_vs_vector(int);
void read_and_sort_words();
void palindrome_driver();

template <typename T>
void fill_container_with_students(int, T &);

int main(){
	student_vector_drive();
	return 0;
}

void palindrome_driver(){
	vector<string> dictionary;
	string s;
	while(cin >> s){
		dictionary.push_back(s);
	}

	vector<string> palindromes = extract_palindromes(dictionary);


	print_vector_of_strings(dictionary);
	cout << "palindromes:" << endl;

	print_vector_of_strings(palindromes);
}

void test_picture_concatenation(){
	vector<string> unframed_picture;

	if(!fill_vector_with_lines(cin, unframed_picture))
		return;

	vector<string> framed_picture = frame(unframed_picture);
	vector<string> centered_picture = center(unframed_picture);

	vector<string> hcat = horizontal_concatenation(unframed_picture, framed_picture);
	vector<string> vcat = vertical_concatenation(framed_picture, hcat);

	print_vector_of_strings(vertical_concatenation(vcat, centered_picture));
}

void student_list_drive(){
	list<Student_info> students;
	Student_info student;
	while(read_student_record(cin, student))
		students.push_back(student);

	print_student_list(students);

	list<Student_info> failingStudents = extract_fails(students);

	cout << endl << "Failing students: " << endl;

	print_student_list(failingStudents);

	cout << endl << "Passing students: " << endl;

	print_student_list(students);
}

void student_vector_drive(){

	vector<Student_info> students;
	Student_info student;
	while(read_student_record(cin, student))
		students.push_back(student);

	print_student_vector(students);

	vector<Student_info> failingStudents = extract_fails(students);

	cout << endl << "Failing students:" << endl;
	print_student_vector(failingStudents);


	cout << endl << "Passing students:" << endl;
	print_student_vector(students);
}

void print_student_vector(const vector<Student_info> &students){
	//get max name length
	string::size_type max_name_length = 0;

	for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
	 max_name_length = max(max_name_length, (it->name).size());
	}

	string padding(5, ' ');

	for(vector<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
		cout << "Name: " << setw(max_name_length)  << it->name << padding << "Grade: " << grade(*it) << endl;
	}
}

void print_student_list(const list<Student_info> & students){
	//get max name length
	string::size_type max_name_length = 0;
	for(list<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
		max_name_length = max(max_name_length, (it->name).size());
	}

	string padding(5, ' ');

	for(list<Student_info>::const_iterator it = students.begin(); it != students.end(); it++){
		cout << "Name: " << setw(max_name_length) << it->name << padding << "Grade: " << grade(*it) << endl;
	}
}


void test_my_string_splitter(){
	string s;
	while(getline(cin, s)){
		vector<string> v = split_string_to_words(s);

		for(vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
			cout << *it << endl;
	}
}

void built_in_string_split(){
	string s;
	while(cin >> s){
		cout << s << endl;
	}
}

//needs to be reversed
string get_column_header(int i){
	stringstream ss;

	//ss contains the reversed column_header thus far.
	while(i > 0){
		int trailing_num = i-1 % 26;
		ss << (char)((int)'A' + trailing_num);
		i = (i - 1)/26;
	}

	return ss.str();
}

template <typename T>
void fill_container_with_students(int num_students, T & container){
	stringstream ss;
	for (int i = 1; i <= num_students; ++i)
	{
		Student_info s;
		s.name = get_column_header(i);

		s.midterm = i % 2 == 0 ? 50 : 100;
		s.final = i % 2 == 0 ? 50 : 100;
		s.hw.push_back(i % 2 == 0 ? 50 : 100);

		container.push_back(s);
	}

}

void test_list_vs_vector(int num_students){
	vector<Student_info> student_vector(num_students);
	list<Student_info> student_list(num_students);

	fill_container_with_students(num_students, student_vector);
	fill_container_with_students(num_students, student_list);

	//start time

	//extract fails

	//end time
}

void read_and_sort_words(){
	list<string> words;
	string s;
	while(cin >> s)
		words.push_back(s);

	words.sort();
	words.reverse();

	for(list<string>::const_iterator it = words.begin(); it != words.end(); ++it){
		cout << *it << endl;
	}


}