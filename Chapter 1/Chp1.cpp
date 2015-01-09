#include <iostream>
#include <string>

int main(){
	std::cout << "What are your names?" << std::endl;
	std::string name;
	std::cin >> name;

	std::cout << "Hello, " << name << std::endl
		<< "And what is yours?" << std::endl;

	std::cin >> name;

	std::cout << "Nice to meet you too, " << name << std::endl;

	return 0;
}