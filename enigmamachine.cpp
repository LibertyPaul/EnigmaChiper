#include "enigmamachine.hpp"

#include <utility>
#include <stdexcept>


EnigmaMachine::EnigmaMachine(std::vector<Rotor> &&rotors, Reflector &&reflector):
	rotors(rotors),
	reflector(reflector)
{
	if(this->rotors.empty())
	{
		throw std::runtime_error("There should be at least one rotor in Enigma machine");
	}
}

EnigmaMachine::EnigmaMachine(const std::vector<Rotor> &rotors, const Reflector &reflector):
	rotors(std::move(std::vector<Rotor>(rotors))),
	reflector(std::move(Reflector(reflector)))
{

}

EnigmaMachine::~EnigmaMachine()
{

}

void EnigmaMachine::setup(const std::vector<uint8_t> &key)
{
	if(key.size() != this->rotors.size())
	{
		throw std::runtime_error("Key vector should be same size as rotor vector");
	}

	for(size_t i = 0; i < key.size(); ++i)
	{
		this->rotors.at(i).drop();
		this->rotors.at(i).rotate(key.at(i));
		this->rotors.at(i).setNullPosition();
	}
}

void EnigmaMachine::rotate()
{
	for(Rotor &rotor : this->rotors)
	{
		rotor.rotate();
		if(rotor.isTurned() == false)
		{
			break;
		}
	}
}

uint8_t EnigmaMachine::encrypt(uint8_t value)
{
	this->rotate();

	for(auto rotor = this->rotors.cbegin(); rotor != this->rotors.cend(); ++rotor)
	{
		value = rotor->transformForward(value);
	}

	value = reflector.transform(value);

	for(auto rotor = this->rotors.crbegin(); rotor != this->rotors.crend(); ++rotor)
	{
		value = rotor->transformBackward(value);
	}

	return value;
}











