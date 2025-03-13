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
	(void)s;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &s){
	(void)s;
	return (*this);
}

void	ScalarConverter::convert(std::string type){
	e_type etype = findType(type);
	// printType(_etype); //for test purpose only
	printConverted(etype, type);
}

/////////////////////////////////////

e_type	findType(std::string type){
	e_type etype = OTHER;

	if (type.empty())
		throw ScalarConverter::WrongTypeException();
	else if (isChar(type))
		etype = CHAR;
	else if (isInt(type))
		etype = INT;
	else if (isFloat(type))
		etype = FLOAT;
	else if (isDouble(type))
		etype = DOUBLE;
	else if (isSpecial(type))
		etype = SPECIAL;
	return (etype);
}

int		isChar(const std::string &type){
	if (type.length() == 1 && !isdigit(type[0]) && isprint(type[0]))
		return (1);
	if (type.length() == 3 && type[0] == '\'' && type[2] == '\'' && isprint(type[1])) //sert au caractere litteraux (ex : '1' ou 'w')
		return (1);
	return (0);
}

int		isInt(const std::string &type){
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
	// long nb = std::atol(type.c_str());
	// if (nb > 2147483647 || nb < -2147483648)
	// 	return (0);
	return (1);
}

size_t	detectChar(std::string str, char c){
	size_t value = 0;
	for (size_t i = 0 ; i < str.length() ; i++)
	{
		if (str[i] == c && value == 0)
			value = i;
		else if (str[i] == c && value != 0)
			return (0);
	}
	if (value == str.length())
		return (0);
	return (value);
}

int	isFloat(const std::string &str){
	size_t dot = detectChar(str, '.');
	if (dot == 0)
		return (0);
	if (str[str.length() - 1] != 'f')
		return (0);
	for (size_t i = 0; i < dot ; i++)
	{
		if (!isdigit(str[i]) && i != 0)
			return (0);
		if (!isdigit(str[i]) && (str[i] != '+' || str[i] != '-'))
			return (0);
	}
	for (size_t i = dot + 1 ; i < str.length() ; i++)
	{
		if (!isdigit(str[i]) && i != (str.length() - 1) && str[i] != 'f')
			return (0);
	}
	return (1);
}

int	isDouble(const std::string &str){
	size_t dot = detectChar(str, '.');
	size_t power = detectChar(str, 'e');
	int sign = 0;
	if (dot == 0)
		return (0);
	if (power != 0 && dot > power)
		return (0);
	for (size_t i = 0; i < dot ; i++) //check before the dot
	{
		if (!isdigit(str[i]) && i != 0)
			return (0);
		if (!isdigit(str[i]) && (str[i] != '+' || str[i] != '-'))
			return (0);
	}
	for (size_t i = dot + 1 ; i < str.length() ; i++) // check after the dot
	{
		if (!isdigit(str[i]) && i > (str.length() -2) && str[i] != 'e')
			return (0);
		if (!isdigit(str[i]) && i > (str.length() -1) && (str[i] != '+' || str[i] != '-'))
			return (0);
		if (str[i] == '+' || str[i] == '-')
		{
			if (sign == 0)
				sign = 1;
			else
				return (0);
		}
	}
	return (1);
}

int	isSpecial(const std::string &str){
	if (str == "nan" || str == "nanf")
		return (1);
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

// void	printType(e_type etype){
// 	std::string str;
// 	if (etype == 0)
// 		str = CHAR;
// 	switch (etype)
// 	{
// 	case 0:
// 		str = "CHAR";
// 		break;
// 	case 1:
// 		str = "INT";
// 		break;
// 	case 2:
// 		str = "FLOAT";
// 		break;
// 	case 3:
// 		str = "DOUBLE";
// 		break;
// 	case 4:
// 		str = "SPECIAL";
// 		break;
// 	default:
// 		str = "OTHER";
// 	}
// 	std::cout << GREEN << "Type is " << str << WHITE << std::endl;
// }



void	printConverted(e_type etype, std::string type){
	switch (etype)
	{
	case 0:
		fromChar(type);
		break;
	case 1:
		fromInt(type);
		break;
	case 2:
		fromFloat(type);
		break;
	case 3:
		fromDouble(type);
		break;
	case 4:
		fromSpecial(type);
		break;
	default:
		throw (ScalarConverter::WrongTypeException());
	}
}

void	printFormat(char c, int i, float f, double d, int precision){
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if (d > 2147483647 || d < -2147483648)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (precision != 1) //change the precision under e+-42
	{
		std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	}
	else //print the basic format
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void	fromChar(const std::string &str){
	char c;
	if (str[0] == '\'')
		c = str[1];
	else
		c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	printFormat(c, i, f, d, 1);
	
}

void	fromInt(const std::string &str){
	int i = std::atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	printFormat(c, i, f, d, 1);
}

void	fromFloat(const std::string &str){
	float f = std::atof(str.c_str());
	char c = static_cast<float>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	printFormat(c, i, f, d, 1);
}

int	getPrecision(const std::string &str){ // calculate precision for print of double
	int precision = 1;
	size_t len = detectChar(str, 'e');
	if (len == str.length() - 1)
		return (1);
	if (len == 0 || str[len+1] != '-')
		return (1);
	std::string newstr;
	if (str[len+1] == '-')
		newstr = str.substr(len + 2);
	else
		newstr = str.substr(len + 1);
	precision = atoi(newstr.c_str());
	return (precision);
}

void	fromDouble(const std::string &str){
	double d = std::atof(str.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	int pre = getPrecision(str);
	if (pre > 42)
		pre = 1;
	printFormat(c, i, f, d, pre);
}

void	fromSpecial(const std::string &str){
	float f = std::atof(str.c_str());
	double d = static_cast<double>(f);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
