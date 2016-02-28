#include "rotorfactory.hpp"
#include "rotorparser.hpp"
#include <algorithm>
#include <chrono>
#include <utility>

RotorFactory::RotorFactory(const std::string &filePath, const size_t rotorCount, const size_t rotorSize):
	Factory(filePath),
	rotorSize(rotorSize),
	rotorCount(rotorCount),
	randomGenerator(std::chrono::system_clock::now().time_since_epoch().count())
{

}

RotorFactory::~RotorFactory()
{

}

Rotor RotorFactory::createRotor() const
{
	std::vector<uint8_t> matching(this->rotorSize);
	int i = 256;
	while(i --> 0)
	{
		matching.at(i) = i;
	}
	std::shuffle(matching.begin(), matching.end(), this->randomGenerator);

	return Rotor(move(matching));
}

void RotorFactory::generate()
{
	for(size_t i = 0; i < this->rotorCount; ++i)
	{
		this->rotors.push_back(std::move(this->createRotor()));
	}
}

void RotorFactory::read(std::istream &src)
{
	this->rotors = std::move(RotorParser::parse(src));
}

void RotorFactory::write(std::ostream &dst) const
{
	RotorParser::serialize(this->rotors, dst);
}
