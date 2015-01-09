#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void writeSquare(int);
void chp2Prog();
void writeRect(int, int);
void writeTriangle1(int);
void writeTriangle2(int);
void printProductForRange();
int main(){
	writeSquare(2);
	writeRect(10, 20);
	writeTriangle1(14);
	writeTriangle2(51);
	printProductForRange();
	return 0;
}

//input should be an odd number greater than 1
void writeTriangle2(int height){
	if(height < 3 || height % 2 == 0)
		return;
	//i rows have been written
	for(int i = 0; i != height - 1; i++){
		if(i == 0)
			cout << string(height - 1, ' ') << '*';
		else
			cout << string(height - 1 - i, ' ') << '*' << string(2 * i, ' ') << '*';
		//write row
		cout << endl;
	}

	//write bottom row
	cout << string(2 * height, '*') << endl;
}
//track sideLen = 2 && 3
void writeTriangle1(int sideLen){
	//write first half of triangle

	//i rows have been written
	for(int i = 0; i != sideLen/2; i++){
		cout << '*';
		if(i != 0)
			cout << string(i, ' ') << '*'; 
		
		//row written
		cout << endl;
	}

	//i rows left to write
	for(int i = (sideLen % 2 == 1) ? sideLen/2 + 1 : sideLen/2; i != 0; i--){
		cout << '*';
		if(i != 1)
			cout << string(i, ' ') << '*';

		//write row
		cout << endl;
	}
}

void writeSquare(int sideLen){
	//write top
	string top(sideLen, '*');
	string midRow = '*' + string(sideLen - 2, ' ') + '*';
	//i rows have been written
	for(int i = 0; i != sideLen; i++){
		if(i == 0 || i == sideLen - 1)
			cout << top;
		else{
			cout << midRow;

		}

		//write row
		cout << endl;
	}
}

void writeRect(int height, int width){
	string top(width, '*');
	string midRow = '*' + string(width - 2, ' ') + '*';

	//i rows have been written
	for(int i = 0; i != height; i++){
		if(i == 0 || i == height - 1)
			cout << top;
		else
			cout << midRow;
		cout << endl;
	}
}
void chp2Prog(){
	cout << "Please enter your name: ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";

	const int topPad = 0;
	const int sidePad = 0;

	const int rows = topPad * 2 + 3;
	const string::size_type cols = sidePad * 2 + 2 + greeting.size();


	//invariant: r rows have been written
	for(int r = 0; r != rows; r++){
	//write a row

		string::size_type c = 0;
		//invariant: c characters have been written
		while(c != cols){
			//start of greeting
			if(r == topPad + 1 && c == sidePad + 1){
				cout << greeting;
				c += greeting.size();
			}else{
				//border character
				if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
					cout << "*";
					++c;
				}
				else{
					string spaces(sidePad, ' ');
					cout << spaces;
					c += spaces.size();
				}
			}
		}

		//write row
		cout << endl;
	}
}

void printProductForRange(){
	int product = 1;

	//i has been included in product
	for(int i = 1; i != 9; i++){
		product *= i + 1;
	}

	cout << product << endl;
}