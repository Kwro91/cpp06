#ifndef DATA_HPP
#define DATA_HPP

#include "Color.hpp"
#include <iostream>
#include <exception>
#include <stdint.h>

struct Data {
		int _id;
		std::string _name;

		Data();
		Data(int id, std::string name);
		~Data();
		Data(const Data &d);
		Data &operator=(const Data &d);
};

std::ostream &operator<<(std::ostream &out, const Data &d);


#endif