#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <array>
#include <cstdint>

class Reflector
{
	std::array<std::pair<uint8_t, uint8_t>, 128> matching;
public:
	Reflector(std::array<std::pair<uint8_t, uint8_t>, 128> &&matching);
	Reflector(const std::array<std::pair<uint8_t, uint8_t>, 128> &matching);
	Reflector(Reflector &&reflector);
	Reflector(const Reflector &reflector);
	~Reflector();

	uint8_t transform(const uint8_t inputPosition) const;

};

#endif // REFLECTOR_HPP
