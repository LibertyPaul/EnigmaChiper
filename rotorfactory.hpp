#ifndef ROTORFACTORY_HPP
#define ROTORFACTORY_HPP

#include "factory.hpp"
#include "rotor.hpp"
#include <vector>
#include <random>


class RotorFactory : public Factory
{
	std::vector<Rotor> rotors;
	size_t rotorSize;
	size_t rotorCount;

	mutable std::default_random_engine randomGenerator;

	Rotor createRotor() const;

	virtual void generate();
	virtual void read(std::istream &src);
	virtual void write(std::ostream &dst) const;

public:
	RotorFactory(const std::string &filePath, const size_t rotorCount, const size_t rotorSize = 256);
	virtual ~RotorFactory();

	std::vector<Rotor> getRotors() const;
};

#endif // ROTORFACTORY_HPP
