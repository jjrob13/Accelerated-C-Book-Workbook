#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;	using std::cin;
using std::cout;	using std::endl;
using std::sort;	using std::string;
using std::streamsize;	using std::setprecision;

double meanGradeCalc();
double medianGradeCalc();
void countDistinctWords();
void mainGradeProg();
void getLongestAndShortestStrings();

int main(){
	getLongestAndShortestStrings();
	return 0;

}

void mainGradeProg() {
	
	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your midterm and final exam grades: ";

	double midterm, final;

	cin >> midterm >> final;

	cout << "Please enter all of your homework grades"
			", followed by end-of-file: ";

	double average = medianGradeCalc();

	streamsize prec = cout.precision();

	cout << "Your final grade was: " << setprecision(3) << average * .4 + midterm*.2 + final*.4 << setprecision(prec) << endl;

}

double meanGradeCalc(){
	int count = 0;
	double sum = 0, x;

	//count grades have been read
	//sum contains the sum for the first count grades
	while(cin >> x){
		++count;
		sum += x;
	}
	if(count == 0){
		cout << "Please enter valid grades" << endl;
		return 1;
	}

	return sum/count;
}


double medianGradeCalc(){
	double x;
	vector<double> homework;

	//homework contains all of the grades
	while(cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_size;

	vec_size size = homework.size();

	if(size == 0){
		cout << "Please enter valid grades" << endl;
		return 1;
	}

	sort(homework.begin(), homework.end());

	vec_size mid = size/2;


	//return median
	return size % 2 == 0 ? (homework[mid - 1] + homework[mid])/2 : homework[mid];
}

void countDistinctWords(){
	cout << "Please enter some words: ";
	vector<string> words;
	string x;

	//words contains all words read
	while(cin >> x)
		words.push_back(x);

	if(words.size() == 0)
		return;

	sort(words.begin(), words.end());

	int currentWordCount = 1;

	//i words have been processed
	for(int i = 1; i != words.size(); i++){
		//words match
		if(words[i].compare(words[i-1]) == 0)
			currentWordCount++;
		else{
			cout << words[i - 1] << " : " << currentWordCount << endl;
			currentWordCount = 1;
		}
	}

	cout << words[words.size() - 1] << " : " << currentWordCount << endl;
}

void getLongestAndShortestStrings(){
	cout << "Please enter a string of words: ";

	string maxString, minString, x;

	cin >> maxString;

	minString = maxString;

	string::size_type max = maxString.size(), min = minString.size();

	//maxString has longest string read, minString has shortest string read
	while(cin >> x){
		if(x.size() < minString.size()){
			minString = x;
			min = x.size();
		}

		if(x.size() > maxString.size()){
			maxString = x;
			max = x.size();
		}
	}

	cout << "Max String : " << maxString << endl << "Min String : " << minString << endl;
}