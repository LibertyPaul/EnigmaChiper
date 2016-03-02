#include "rotorfactory.hpp"
#include "rotorparser.hpp"
#include <algorithm>
#include <chrono>
#include <utility>
#include <fstream>

RotorFactory::RotorFactory(const std::string &filePath, const size_t rotorSize):
	filePath(filePath),
	rotorSize(rotorSize),
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

std::vector<Rotor> RotorFactory::regenerate(const size_t count)
{
	this->rotors.clear();
	this->rotors.reserve(count);
	for(size_t i = 0; i < count; ++i)
	{
		this->rotors.push_back(this->createRotor());
	}

	std::ofstream dst(this->filePath, std::ios_base::trunc | std::ios_base::binary);
	this->write(dst);

	return this->rotors;
}

void RotorFactory::read(std::istream &src)
{
	this->rotors = std::move(RotorParser::parse(src));
}

void RotorFactory::write(std::ostream &dst) const
{
	RotorParser::serialize(this->rotors, dst);
}

std::vector<Rotor> RotorFactory::read()
{
	std::ifstream src(this->filePath, std::ios_base::in | std::ios_base::binary);
	this->read(src);
	return this->rotors;
}
