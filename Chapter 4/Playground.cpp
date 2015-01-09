#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::cout;	using std::cin;
using std::domain_error;	using std::endl;
using std::setw;		using std::stringstream;
using std::istream;

void printSquares(double);
template <typename T>
string toString(T);

istream& fillVector(istream&, vector<string>&);
void wordCountEachWordOccurence(vector<string>);


/*
MAIN
*/

int main(){
	//wordCount words
	vector<string> vec;
	fillVector(cin, vec);
	cout << "Num words = " << vec.size() << endl;

	wordCountEachWordOccurence(vec);
	return 0;
}

void printSquares(double n){
	if(n < 1)
		throw domain_error("printSquares argument must be >= 1");

	//get length of longest number
	string longestNumStr = toString(n * n);

	std::streamsize maxWidth = longestNumStr.size();
	//original width
	std::streamsize original_width = cout.width();

	string padding(5, ' ');

	//i-1 rows have been printed
	for(int i = 1; i < n; i++){
		unsigned long square = i * i;
		cout << setw(maxWidth) << i << padding << setw(maxWidth) << square << endl;
	}

	cout << setw(maxWidth) << n << padding << setw(maxWidth) << longestNumStr << setw(original_width) << endl;

}

template <typename T>
string toString(T num){
	stringstream ss;
	ss << num;
	return ss.str();
}


istream & fillVector(istream & in, vector<string> & vec){
	if(!in)
		return in;
	vec.clear();

	string x;
	while(in >> x)
		vec.push_back(x);

	in.clear();

	return in;
}

void wordCountEachWordOccurence(vector<string> words){
	if(words.size() == 0)
		throw domain_error("Empty vector!");

	std::sort(words.begin(), words.end());

	//get length of longest word
	string::size_type maxLen = 0;

	//maxLen is length of longest string
	for(int i = 0; i != words.size(); i++){
		maxLen = std::max(maxLen, words[i].size());
	}

	vector<string>::size_type wordCount = 1;
	string padding(5, ' ');
	//INV: i words have been acwordCounted for
	//wordCount represents the number of occurences of words[i - 1] seen so far
	for(int i = 1; i != words.size(); i++){
		if(words[i] == words[i - 1])
			wordCount++;
		else{
			cout << setw(maxLen + 2) << words[i - 1] << padding << wordCount << endl;
			wordCount = 1;
		}
	}

	cout << setw(maxLen + 2) << words[words.size() - 1] << padding << wordCount << endl;
}