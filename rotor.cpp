#include "rotor.hpp"

#include <climits>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <utility>

Rotor::Rotor(std::vector<uint8_t> &&matching):
	matching(matching),
	nullPosition(0),
	position(nullPosition)
{
	if(this->matching.empty())
	{
		throw std::runtime_error("Rotor can't be empty");
	}
	const auto it = std::adjacent_find(this->matching.cbegin(), this->matching.cend());
	if(it != this->matching.cend())
	{
		throw std::runtime_error("Matching has repeating value: " + std::to_string(*it));
	}
}

Rotor::Rotor(const std::vector<uint8_t> &matching)
{
	std::vector<uint8_t> tmp(matching);
	Rotor(move(tmp));
}

Rotor::Rotor(Rotor &&rotor):
	matching(std::move(rotor.matching)),
	nullPosition(rotor.nullPosition),
	position(rotor.position)
{

}

Rotor::Rotor(const Rotor &rotor):
	matching(rotor.matching),
	nullPosition(rotor.nullPosition),
	position(rotor.position)
{

}

Rotor::~Rotor()
{

}

void Rotor::rotate(const uint8_t distance)
{
	this->position += distance;
}

void Rotor::drop()
{
	this->nullPosition = 0;
	this->position = this->nullPosition;
}

void Rotor::setNullPosition()
{
	this->nullPosition = this->position;
}

bool Rotor::isTurned() const
{
	return this->position == this->nullPosition;
}

uint8_t Rotor::transformForward(const uint8_t absoluteInputPosition) const
{
	const uint8_t relativeInputPosition = absoluteInputPosition - this->position;
	const uint8_t relativeOutputPosition = this->matching.at(relativeInputPosition);
	const uint8_t absoluteOutputPosition = relativeOutputPosition + this->position;

	return absoluteOutputPosition;
}

uint8_t Rotor::transformBackward(const uint8_t absoluteInputPosition) const
{
	const uint8_t relativeInputPosition = absoluteInputPosition - this->position;
	uint8_t relativeOutputPosition = 0;
	for(const uint8_t value : this->matching)
	{
		if(value == relativeInputPosition)
		{
			break;
		}
		++relativeOutputPosition;
	}
	const uint8_t absoluteOutputPosition = relativeOutputPosition + this->position;

	return absoluteOutputPosition;
}
