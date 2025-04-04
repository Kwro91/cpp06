#include "../includes/ScalarConverter.hpp"

void	ft_error(std::string str){
	std::cerr << RED << str << WHITE << std::endl;
}

int main (int ac, char **av) {
	if (ac != 2)
		return (ft_error("Error: one arg required. (./converter [input])"), 0);
	std::string s = av[1];
	try {
		ScalarConverter::convert(s);
	}catch (std::exception &s){
		std::cerr << YELLOW << s.what() << std::endl;
	}
	return 0;
}