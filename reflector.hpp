#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "reflectorparser.hpp"
#include <vector>
#include <cstdint>

class ReflectorParser;

class Reflector
{
	std::vector<uint8_t> matching;
public:
	Reflector(std::vector<uint8_t> &&matching);
	Reflector(const std::vector<uint8_t> &matching);
	Reflector(Reflector &&reflector);
	Reflector(const Reflector &reflector);
	~Reflector();

	uint8_t transform(const uint8_t inputPosition) const;

	friend class ReflectorParser;
};

#endif // REFLECTOR_HPP
