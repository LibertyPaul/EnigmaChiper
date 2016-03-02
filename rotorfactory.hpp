#ifndef ROTORFACTORY_HPP
#define ROTORFACTORY_HPP

#include "rotor.hpp"
#include <vector>
#include <random>


class RotorFactory
{
	std::string filePath;
	std::vector<Rotor> rotors;
	size_t rotorSize;

	mutable std::default_random_engine randomGenerator;

	Rotor createRotor() const;

	void read(std::istream &src);
	void write(std::ostream &dst) const;

public:
	RotorFactory(const std::string &filePath, const size_t rotorSize = 256);
	virtual ~RotorFactory();

	std::vector<Rotor> read();
	std::vector<Rotor> regenerate(const size_t count);

};

#endif // ROTORFACTORY_HPP
