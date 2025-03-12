#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include "Color.hpp"

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	OTHER
};

class ScalarConverter {
	public:
		ScalarConverter();
		virtual ~ScalarConverter() = 0;
		ScalarConverter(const ScalarConverter &s);
		ScalarConverter &operator=(const ScalarConverter &s);

		static void			convert(std::string type);
		
		class WrongTypeException : public std::exception {
			public:
			const char	*what() const throw();
		};
	};

	int				isChar(const std::string &str);
	int				isInt(const std::string &str);
	int				isFloat(const std::string &str);
	int				isDouble(const std::string &str);
	int				isSpecial(const std::string &str);
	e_type			findType(std::string type);
	void			printConverted(e_type etype, std::string type);
	void			fromChar(const std::string &str);
	void			fromInt(const std::string &str);
	void			fromFloat(const std::string &str);
	void			fromDouble(const std::string &str);
	void			fromSpecial(const std::string &str);
	
	void			printType(e_type etype); //for test only
#endif