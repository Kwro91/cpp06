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
	private:
		static e_type	_etype;
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &s);
		ScalarConverter &operator=(const ScalarConverter &s);

		static void			convert(std::string type);
		
		class WrongTypeException : public std::exception {
			public:
			const char	*what() const throw();
		};
	};
	e_type			findType(std::string type);
	void			printType(e_type etype);
	void			printConverted(e_type etype, std::string type);
	void			fromChar(std::string str);
	void			fromInt(std::string str);
	void			fromFloat(std::string str);
	void			fromDouble(std::string str);
	void			fromSpecial(std::string str);
	void			fromOther(std::string str);


#endif