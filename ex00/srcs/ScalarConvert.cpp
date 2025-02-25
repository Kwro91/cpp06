#include "../includes/ScalarConverter.hpp"

const char	*ScalarConverter::WrongTypeException::what() const throw(){
	return ("Exception: Wrong input on type");
}

//////////////////////////////////////////////////////

ScalarConverter::ScalarConverter(){

}

ScalarConverter::~ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &s){
	setType(s._type);
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &s){
	setType(s._type);
	return (*this);
}

void	ScalarConverter::convert(std::string type){
	findType(type);
}

void	ScalarConverter::setType(std::string type){_type = type;}

const std::string	&ScalarConverter::getType() const{return (_type);}

/////////////////////////////////////

int		isChar(std::string type){
	if (type.length() == 1 && !isdigit(type[0]) && isprint(type[0]))
		return (1);
	if (type.length() == 3 && type[0] == '\'' && type[2] == '\'') //sert au caractere litteraux (ex : '1' ou 'w')
		return (1);
	return (0);
}

int		isInt(std::string type){
	size_t i = 0;
	size_t digit = 0;
	if (type[0] == '-' || type[0] == '+')
		i++;
	while ((i < type.length()))
	{
		if (!isdigit(type[i]))
			return (0);
		digit++;
		if (digit > 10)
			return (0);
		i++;
	}
	long nb = std::atol(type.c_str());
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

e_type	findType(std::string type){
	if (type.empty())
		throw ScalarConverter::WrongTypeException();
	if (isChar(type))
		return (CHAR);
	if (isInt(type))
		return (INT);
	return (OTHER);
}