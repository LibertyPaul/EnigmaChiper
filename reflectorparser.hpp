#ifndef REFLECTORPARSER_HPP
#define REFLECTORPARSER_HPP

#include "reflector.hpp"
#include "parser.hpp"
#include <vector>
#include <istream>

class Reflector;

class ReflectorParser : Parser
{
public:
	static Reflector parse(std::istream &src);
	static void serialize(const Reflector &reflector, std::ostream &dst);
};

#endif // REFLECTORPARSER_HPP
