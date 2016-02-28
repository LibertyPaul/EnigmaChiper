#ifndef REFLECTORFACTORY_HPP
#define REFLECTORFACTORY_HPP

#include "factory.hpp"
#include "reflector.hpp"
#include <random>
#include <memory>

class ReflectorFactory : public Factory
{
	std::shared_ptr<Reflector> reflector;
	const size_t reflectorSize;

	mutable std::default_random_engine randomGenerator;

	Reflector createReflector() const;

	virtual void generate();
	virtual void read(std::istream &src);
	virtual void write(std::ostream &dst) const;

public:
	ReflectorFactory(const std::string &filePath, const size_t reflectorSize = 256);
	virtual ~ReflectorFactory();

	Reflector getReflector() const;
};

#endif // REFLECTORFACTORY_HPP
