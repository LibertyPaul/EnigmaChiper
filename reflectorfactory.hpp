#ifndef REFLECTORFACTORY_HPP
#define REFLECTORFACTORY_HPP

#include "reflector.hpp"
#include <random>
#include <memory>

class ReflectorFactory
{
	const size_t reflectorSize;
	mutable std::default_random_engine randomGenerator;

	Reflector createReflector() const;

public:
	ReflectorFactory(const size_t reflectorSize = 256);
	virtual ~ReflectorFactory();

	Reflector getReflector() const;
};

#endif // REFLECTORFACTORY_HPP
