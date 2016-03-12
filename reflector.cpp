#include "reflector.hpp"
#include <utility>
#include <stdexcept>

Reflector::Reflector(std::array<std::pair<uint8_t, uint8_t>, 128> &&matching): matching(matching)
{

	std::array<bool, 256> exist;
	for(auto &value : exist)
	{
		value = false;
	}


	for(const auto &match : this->matching)
	{
		if(exist.at(match.first))
		{
			throw std::runtime_error("Incorrect matching");
		}
		exist.at(match.first) = true;

		if(exist.at(match.second))
		{
			throw std::runtime_error("Incorrect matching");
		}
		exist.at(match.second) = true;
	}

}

Reflector::Reflector(const std::array<std::pair<uint8_t, uint8_t>, 128> &matching):
	Reflector(move(std::array<std::pair<uint8_t, uint8_t>, 128>(matching)))
{

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
	for(const auto &match : this->matching)
	{
		if(inputPosition == match.first)
		{
			return match.second;
		}

		if(inputPosition == match.second)
		{
			return match.first;
		}
	}

}
