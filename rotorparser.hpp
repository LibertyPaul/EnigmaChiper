#ifndef ROTORPARSER_HPP
#define ROTORPARSER_HPP

#include "rotor.hpp"
#include "parser.hpp"
#include <vector>
#include <istream>

class Rotor;

class RotorParser : Parser
{
public:
	static std::vector<Rotor> parse(std::istream &src);
	static void serialize(const std::vector<Rotor> &rotors, std::ostream &dst);
};

#endif // ROTORPARSER_HPP
