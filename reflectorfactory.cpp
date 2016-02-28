#include "reflectorfactory.hpp"
#include <algorithm>

ReflectorFactory::ReflectorFactory(const std::string &filePath, const size_t reflectorSize):
	Factory(filePath),
	reflectorSize(reflectorSize)
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
	std::vector<uint8_t> matching(this->reflectorSize);
	int i = 256;
	while(i --> 0)
	{
		matching.at(i) = i;
	}

	while(true)
	{
		std::shuffle(matching.begin(), matching.end(), this->randomGenerator);
		try
		{
			return Reflector(std::move(matching));
		}
		catch(std::runtime_error &)
		{

		}
	}
}

void ReflectorFactory::generate()
{
	this->reflector = std::make_shared<Reflector>(std::move(this->createReflector()));
}

void ReflectorFactory::read(std::istream &src)
{
	this->reflector = std::make_shared<Reflector>(std::move(ReflectorParser::parse(src)));
}

void ReflectorFactory::write(std::ostream &dst) const
{
	ReflectorParser::serialize(*this->reflector.get(), dst);
}

Reflector ReflectorFactory::getReflector() const
{
	return *this->reflector.get();
}
