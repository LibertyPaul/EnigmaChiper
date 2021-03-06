#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "rotorparser.hpp"
#include <vector>
#include <cstdint>

class RotorParser;

class Rotor
{
    std::vector<uint8_t> matching;
    uint8_t nullPosition;	// which element is zero
    uint8_t position;		// how far we get from nullElement


public:
	Rotor(std::vector<uint8_t> &&matching);
	Rotor(const std::vector<uint8_t> &matching);
	Rotor(Rotor &&rotor);
	Rotor(const Rotor &rotor);
    ~Rotor();

	void rotate(const uint8_t distance = 1);
	void drop();
	void setNullPosition();
    bool isTurned() const;
    uint8_t transformForward(const uint8_t absoluteInputPosition) const;
    uint8_t transformBackward(const uint8_t absoluteInputPosition) const;

	friend class RotorParser;
};

#endif // ROTOR_HPP
