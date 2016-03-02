#ifndef ENIGMAMACHINE_HPP
#define ENIGMAMACHINE_HPP

#include "rotor.hpp"
#include "reflector.hpp"
#include <vector>

class EnigmaMachine
{
	std::vector<Rotor> rotors;
	Reflector reflector;

	void rotate();
public:
	EnigmaMachine(std::vector<Rotor> &&rotors, Reflector &&reflector);
	EnigmaMachine(const std::vector<Rotor> &rotors, const Reflector &reflector);
	~EnigmaMachine();

	void setup(const std::vector<uint8_t> &key);
	uint8_t encrypt(uint8_t value);
};

#endif // ENIGMAMACHINE_HPP
