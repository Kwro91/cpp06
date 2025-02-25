#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Color.hpp"

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class ScalarConverter {
	private:
		std::string _type;
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &s);
		ScalarConverter &operator=(const ScalarConverter &s);

		const std::string	&getType() const;
		void				setType(std::string type);
		static void			convert(std::string type);

		class WrongTypeException : public std::exception {
			public:
			const char	*what() const throw();
		};
	};
	e_type	findType(std::string type);


#endif