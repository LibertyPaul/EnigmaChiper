#include "reflectorfactory.hpp"
#include <algorithm>

ReflectorFactory::ReflectorFactory(const size_t reflectorSize):
	reflectorSize(reflectorSize),
	randomGenerator(42)
{
	if(this->reflectorSize < 2)
	{
		throw std::runtime_error("Reflector size should be > 1");
	}
}

ReflectorFactory::~ReflectorFactory()
{

}

Reflector ReflectorFactory::createReflector() const
{
	std::array<uint8_t, 256> raw;
	int i = 0;
	for(auto &value : raw)
	{
		value = i++;
	}

	std::shuffle(raw.begin(), raw.end(), this->randomGenerator);



	std::array<std::pair<uint8_t, uint8_t>, 128> matching;

	for(size_t i = 0; i < 128; ++i)
	{
		matching[i].first = raw[i * 2];
		matching[i].second = raw[i * 2 + 1];
	}

	return Reflector(matching);
}

Reflector ReflectorFactory::getReflector() const
{
	return this->createReflector();
}
