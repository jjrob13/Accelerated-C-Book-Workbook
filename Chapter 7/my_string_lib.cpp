#include "my_string_lib.h"
#include <iostream>
#include <algorithm>


using std::find;
using std::cout;	using std::endl;
using std::vector;	using std::list;
using std::string;
using std::istream;	using std::map;


vector<string> split_string_to_words(const string & s){
	vector<string> result;
	typedef string::size_type string_size;

	string_size i = 0;

	//i characters have been processed
	while(i != s.size()){

		//[original i, i) were white space
		while(i != s.size() && isspace(s[i]))
			i++;

		string_size j = i;
		//[i, j) is word that should be added to collection of words
		while(j != s.size() && !isspace(s[j])){
			j++;
		}

		//we found some non-whitespace
		if(i != j){
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}

	return result;
}

istream & fill_vector_with_lines(istream & in, vector<string> & v){
	if(!in)
		return in;

	string s;
	while(std::getline(in, s)){
		v.push_back(s);
	}

	in.clear();

	return in;
}

void print_vector_of_strings(const vector<string> & vec){
	for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); ++it){
		cout << *it << endl;
	}
}

//pallap
//palap
bool is_palindrome(const string & str){
	for(int i = 0; i != str.size()/2; i++){
		if(str[i] != str[str.size() - i - 1])
			return false;
	}

	return true;
}


vector<string> extract_palindromes(vector<string> & dictionary){
	vector<string> palindromes;

	vector<string>::iterator it = dictionary.begin();

	while(it != dictionary.end()){
		if(is_palindrome((string) *it)){
			palindromes.push_back(*it);
			it = dictionary.erase(it);
		}else{
			it++;
		}
	}

	return palindromes;
}

list<string> extract_palindromes(list<string> & dictionary){
	list<string> palindromes;

	list<string>::iterator it = dictionary.begin();

	while(it != dictionary.end()){
		if(is_palindrome((string) *it)){
			palindromes.push_back(*it);
			it = dictionary.erase(it);
		}else{
			it++;
		}
	}

	return palindromes;
}

map<string, vector<int> > xref(istream & in, vector<string> parse_string(const string & str)){
	map<string, vector<int> > result_map;
	int line_num = 1;

	//line_num is one more than the number of lines that have been read.
	for(string line; std::getline(in, line); line_num++){
		vector<string> words_on_line = parse_string(line);

		//add to map
		for(vector<string>::const_iterator it = words_on_line.begin(); it != words_on_line.end(); it++){
			//add line_num to map for specific word if it has not been previously added
			if(find(result_map[*it].begin(), result_map[*it].end(), line_num) == result_map[*it].end())
				result_map[*it].push_back(line_num);
		}
	}

	//clear istream
	in.clear();

	return result_map;
}