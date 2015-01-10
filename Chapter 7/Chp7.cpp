#include <iostream>
#include <map>
#include <string>
#include "my_string_lib.h"
#include <vector>
#include "url_parser.h"
#include "grammar_processor.h"
#include <utility>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <ios>
#include "grade.h"
#include "Student_info.h"

using std::map;		using std::cout;
using std::endl;	using std::cin;
using std::string;	using std::vector;
using std::pair;
void map_word_count();
void xref_driver();
void print_grammar();

void print_string_int_map(map<string, int> map_to_print){
	//find max string key length
	string::size_type maxlen = 0;


	for(map<string, int>::const_iterator it = map_to_print.begin(); it != map_to_print.end(); it++){
		maxlen = std::max(it->first.size(), maxlen);
	}

	string padding(5, ' ');

	for(map<string, int>::const_iterator it = map_to_print.begin(); it != map_to_print.end(); it++){
		cout << std::setw(maxlen) << it->first << padding << it->second << endl;
	}
}


void grade_distribution_driver(){
	vector<Student_info> students;
	Student_info s;
	while(read_student_record(cin, s)){
		students.push_back(s);
	}

	print_string_int_map(get_grade_distribution(students));
}

int main(){
	xref_driver();
	return 0;
}

void xref_driver(){
	map<string, vector<int> > words_with_line_nums = xref(cin);

	//print all map entries
	for(map<string, vector<int> >::const_iterator it = words_with_line_nums.begin(); it != words_with_line_nums.end(); it++){
		cout << it->first << "\t appears on line(s): ";

		//print line numbers
		for(vector<int>::const_iterator line_num_it = (it->second).begin(); line_num_it != (it->second).end(); line_num_it++){
			cout << *line_num_it;

			if(line_num_it + 1 != (it->second).end())
				cout << ", ";
		}

		cout << endl;
	}
}
bool compare_word_counts(const pair<string, int> & word1, const pair<string, int> & word2){
	return word1.second < word2.second;
}
void map_word_count(){
	string s;
	map<string, int> counters;

	while(cin >> s){
		counters[s]++;
	}

	//add all entries to vector
	vector<pair<string, int> > vec;

	std::copy(counters.begin(), counters.end(), std::back_inserter(vec));

	std::sort(vec.begin(), vec.end(), compare_word_counts);



	for(vector<pair<string, int> >::const_iterator it = vec.begin(); it != vec.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}
}

void print_grammar(){
	vector<string> sentence = create_sentence_from_grammar(cin, "<sentences>");

	print_vector_of_strings(sentence);

}