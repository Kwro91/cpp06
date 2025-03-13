#ifndef DATA_HPP
#define DATA_HPP

#include "Color.hpp"
#include <iostream>
#include <exception>

class Data {

	private :

	
	public :
		Data();
		virtual ~Data() = 0;
		Data(const Data &s);
		Data &operator=(const Data &s);
		
};

#endif