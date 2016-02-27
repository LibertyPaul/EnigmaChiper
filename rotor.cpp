#include "rotor.hpp"

#include <climits>
#include <set>

Rotor::Rotor(const vector<uint8_t> &matching)
{
    if(matching.size() != 256)
    {
        throw std::invalid_argument("Incorrect matching size");
    }

    std::set<uint8_t> uniqueElements;
    for(const uint8_t value : matching)
    {
        uniqueElements.insert(value);
    }
    if(uniqueElements.size() != matching.size())
    {
        throw std::invalid_argument("There were detected duplicates in `matching` argument");
    }

    this->matching = matching;
}

Rotor::~Rotor()
{

}

void Rotor::rotate()
{
    ++this->position;
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
