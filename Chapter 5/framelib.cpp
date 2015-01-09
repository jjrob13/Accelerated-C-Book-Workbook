#include <stdexcept>
#include <algorithm>
#include <sstream>
#include "framelib.h"
using std::stringstream;
using std::domain_error;
using std::vector;
using std::string;


//1. get length of longest row
//2. frame picture with * using length of longest row for right side
vector<string> frame(const vector<string> & picture){
	if(picture.size() == 0)
		throw domain_error("Cannot frame empty picture.");

	vector<string> result;

	string::size_type maxlen = 0;

	//1.
	for(vector<string>::const_iterator it = picture.begin(); it != picture.end(); ++it){
		maxlen = std::max(maxlen, it->size());
	}

	string border(maxlen + 4, '*');
	result.push_back(border);

	//2
	stringstream ss;
	for(vector<string>::const_iterator it = picture.begin(); it != picture.end(); ++it){
		ss << "* " << *it << string(maxlen - it->size(), ' ') << " *";
		result.push_back(ss.str());
		ss.str("");
	}

	result.push_back(border);

	return result;


}

vector<string> vertical_concatenation(const vector<string> & top, const vector<string> & bottom){
	vector<string> result = top;
	result.insert(result.end(), bottom.begin(), bottom.end());
	return result;
}

//returns a vector that represents the two pictures side-by-side with a single space between the two.
vector<string> horizontal_concatenation(const vector<string> & left, const vector<string> & right){
	vector<string> result;

	//get total width of the left picture
	string::size_type width_left = 0;

	for(vector<string>::const_iterator it = left.begin(); it != left.end(); ++it){
		width_left = std::max(it->size(), width_left);
	}

	vector<string>::const_iterator left_iterator = left.begin(), right_iterator = right.begin();

	while(left_iterator != left.end() || right_iterator != right.end()){
		stringstream row;
		if(left_iterator != left.end()){
			row << *left_iterator;
			left_iterator++;
		}

		//adding one for the space
		row << string(width_left - row.str().size() + 1, ' ');

		if(right_iterator != right.end()){
			row << *right_iterator;
			right_iterator++;
		}

		result.push_back(row.str());
	}

	return result;
}


vector<string> center(const vector<string> & vec){
	vector<string> result;

	//find max len
	string::size_type maxlen = 0;
	for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++){
		maxlen = std::max(maxlen, it->size());
	}

	string border(maxlen + 4, '*');

	result.push_back(border);

	for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++){
		stringstream ss;

		string::size_type total_padding = maxlen - it->size();

		string::size_type left_padding = total_padding/2;
		string::size_type right_padding = total_padding - left_padding;

		ss << "* " << string(left_padding, ' ') << *it << string(right_padding, ' ') << " *";

		result.push_back(ss.str());
	}

	result.push_back(border);

	return result;
}