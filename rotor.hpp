#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <vector>


class Rotor
{
    std::vector<uint8_t> matching;
    uint8_t nullPosition;	// which element is zero
    uint8_t position;		// how far we get from nullElement


public:
    Rotor(const std::vector<uint8_t> &matching);
    ~Rotor();

    void rotate();
    bool isTurned() const;
    uint8_t transformForward(const uint8_t absoluteInputPosition) const;
    uint8_t transformBackward(const uint8_t absoluteInputPosition) const;
};

#endif // ROTOR_HPP
