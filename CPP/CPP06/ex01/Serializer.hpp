
#ifndef	SERIALIZER_HPP
	#define	SERIALIZER_HPP

#include 	<iostream>
#include	<stdint.h>

struct Data
{
	unsigned int	id;
	std::string		message;
};

class Serializer{
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
	
		Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer&);
		~Serializer();

};

#endif
