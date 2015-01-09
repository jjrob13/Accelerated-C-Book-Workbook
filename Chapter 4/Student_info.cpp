#include "Student_info.h"
#include <stdexcept>
using std::istream;
using std::cin;		using std::cout;
using std::domain_error;	using std::string;
using std::vector;			using std::endl;

istream & read_hw(istream &, vector<double>&);

bool compare(const Student_info &s1, const Student_info &s2){
	return s1.name < s2.name;
}

//tested
istream & read_student_record(istream & in, Student_info & student){
	if(!in)
		throw domain_error("Unable to read from input stream");

	string name;
	double midterm, final;
	in >> student.name;

	in >> student.midterm >> student.final;

	//?????why can I not have this
	// if(!in)
	// 	throw domain_error("Bad Input!");
	//-----
	//Answer: this function will return a 'false' value if the read was unsuccessful.  Because of this, the last call
	//			will always create a garbage Student_info object, but that will be later discarded.
	read_hw(in, student.hw);

	return in;
}


//works as expected
istream& read_hw(istream & in, vector<double> & hw){
	if(in){
		hw.clear();
		double x;
		while(in >> x)
			hw.push_back(x);



		//clear istream for next use
		in.clear();
	}

	return in;
}