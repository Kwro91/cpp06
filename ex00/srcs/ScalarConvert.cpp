#include "../includes/ScalarConverter.hpp"

const char	*ScalarConverter::WrongTypeException::what() const throw(){
	return ("Exception: Wrong input on type");
}

//////////////////////////////////////////////////////

e_type ScalarConverter::_etype = OTHER;

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
	_etype = findType(type);
	printType(_etype);
	printConverted(_etype, type);
}

/////////////////////////////////////

int		isChar(std::string type){
	if (type.length() == 1 && !isdigit(type[0]) && isprint(type[0]))
		return (1);
	if (type.length() == 3 && type[0] == '\'' && type[2] == '\'' && isprint(type[1])) //sert au caractere litteraux (ex : '1' ou 'w')
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

int	isSpecial(std::string str){
	if (str == "nan" || str == "nanf")
		return (1);
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

void	printType(e_type etype){
	std::string str;
	if (etype == 0)
		str = CHAR;
	switch (etype)
	{
	case 0:
		str = "CHAR";
		break;
	case 1:
		str = "INT";
		break;
	case 2:
		str = "FLOAT";
		break;
	case 3:
		str = "DOUBLE";
		break;
	case 4:
		str = "SPECIAL";
		break;
	default:
		str = "OTHER";
	}
	std::cout << GREEN << "Type is " << str << WHITE << std::endl;
}

e_type	findType(std::string type){
	e_type etype = OTHER;

	if (type.empty())
		throw ScalarConverter::WrongTypeException();
	if (isChar(type))
		etype = CHAR;
	if (isInt(type))
		etype = INT;
	if (isFloat(type))
		etype = FLOAT;
	if (isDouble(type))
		etype = DOUBLE;
	if (isSpecial(type))
		etype = SPECIAL;
	return (etype);
}


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
		fromOther(type);
	}
}

void	printFormat(std::string c, int i, float f, double d, int precision){
	std::cout << "char: " << c << std::endl;
	if (d > 2147483647 || d < -2147483648)
		std::cout << "int: " << "Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
}

void	fromChar(std::string str){
	std::cout << "char: " << str << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << "Impossible" << std::endl;
	std::cout << "double: " << "Impossible" << std::endl;
}

void	fromInt(std::string str){
	int i = std::atoi(str.c_str());
	str = "Non displayable";
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	printFormat(str, i, f, d, 1);
}

void	fromFloat(std::string str){
	float f = std::atof(str.c_str());
	str = "*";
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	printFormat(str, i, f, d, 1);
}

int	getPrecision(std::string str){ // calcule la precision pour l'affichage des double
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

void	fromDouble(std::string str){
	double d = std::atof(str.c_str());
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	int pre = getPrecision(str);
	str = "*";
	printFormat(str, i, f, d, pre);
}

void	fromSpecial(std::string str){
	if (str == "nanf")
		str = "nan";
	else if (str == "+inff")
		str = "+inf";
	else if (str == "-inff")
		str = "-inf";
	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << str << "f" <<  std::endl;
	std::cout << "double: " << str << std::endl;
}

void	fromOther(std::string str){
	(void)str;
}