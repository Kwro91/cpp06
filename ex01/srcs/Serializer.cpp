#include "../includes/Serializer.hpp"

Serializer::Serializer(){

}

Serializer::~Serializer(){

}

Serializer::Serializer(const Serializer &s){
	(void)s;
};

Serializer	&Serializer::operator=(const Serializer &s){
	(void)s;
	return (*this);
};

uintptr_t	Serializer::serialize(Data *ptr){
	uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data	*Serializer::deserialize(uintptr_t raw){
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}