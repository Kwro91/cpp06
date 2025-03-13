#include "../includes/Data.hpp"

Data::Data(): _id(42), _name("Zeldirth") {
	
}

Data::Data(int id, std::string name) : _id(id), _name(name){

}

Data::~Data(){

}

Data::Data(const Data &d){
	_id = d._id;
	_name = d._name;
}

Data	&Data::operator=(const Data &d){
	_id = d._id;
	_name = d._name;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Data &d){
	out << "Data: " << " id: " <<  d._id << ", name: " << d._name;
	return (out);	
}