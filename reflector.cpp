#include "reflector.hpp"
#include <utility>
#include <stdexcept>

Reflector::Reflector(std::vector<uint8_t> &&matching): matching(matching)
{
	for(size_t i = 0; i < this->matching.size(); ++i)
	{
		if(i == this->matching.at(i))
		{
			throw std::runtime_error("Incorrect reflector matching");
		}
	}
}

Reflector::Reflector(const std::vector<uint8_t> &matching)
{
	std::vector<uint8_t> tmp(matching);
	Reflector(move(tmp));
}

Reflector::Reflector(Reflector &&reflector): matching(std::move(reflector.matching))
{

}

Reflector::Reflector(const Reflector &reflector): matching(reflector.matching)
{

}

Reflector::~Reflector()
{

}

uint8_t Reflector::transform(const uint8_t inputPosition) const
{
	return this->matching.at(inputPosition);
}
