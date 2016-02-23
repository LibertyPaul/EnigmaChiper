#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <vector>


class Rotor
{
	
	
	std::vector<uint8_t> matching;
	uint8_t nullPosition;	// which element is zero
	uint8_t position;		// how far we get from nullElement
	
	
	Rotor(const std::vector<uint8_t> &matching);
public:
	~Rotor();
};

#endif // ROTOR_HPP
