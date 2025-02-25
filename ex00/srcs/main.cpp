#include "../includes/ScalarConverter.hpp"

int main () {
	ScalarConverter test;
	std::string s = "coucou";
	try {
		test.convert(s);
	}catch (std::exception &s){
		std::cerr << YELLOW << s.what() << std::endl;
	}
	return 0;
}