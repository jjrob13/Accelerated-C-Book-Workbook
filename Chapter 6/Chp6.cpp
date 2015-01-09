#include <vector>
#include "url_parser.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Student_info.h"
#include <algorithm>
#include "grade.h"
#include <iterator>
#include <numeric>

using std::cin;		using std::cout;
using std::endl;	using std::stringstream;
using std::vector;	using std::string;

void student_analysis();
string concatenate_all_elements(const vector<string> &);
int main(){
	vector<string> vec(10, string("John James "));

	string result = concatenate_all_elements(vec);

	cout << result << endl;
	return 0;
}

void student_analysis(){
	Student_info student;
	vector<Student_info> all_completed, missed;
	while(read_student_record(cin, student)){
		if(find(student.hw.begin(), student.hw.end(), 0) == student.hw.end())
			all_completed.push_back(student);
		else
			missed.push_back(student);
	}

	if(!all_completed.empty() && !missed.empty())
		write_grade_analysis(cout, all_completed, missed);


}

void url_test(){
	string s;
	stringstream ss;
	while(getline(cin, s)){
		ss << s;
		ss << '\n';
	}

	vector<string> urls = extract_urls(ss.str());

	for(vector<string>::const_iterator it = urls.begin(); it != urls.end(); it++){
		cout << *it << endl;
	}
}


string concatenate_all_elements(const vector<string> & vec){
	return std::accumulate(vec.begin(), vec.end(), string(""));
}