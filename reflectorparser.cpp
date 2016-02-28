#include "reflectorparser.hpp"
#include <utility>

Reflector ReflectorParser::parse(std::istream &src)
{
	std::string currentLine;
	std::getline(src, currentLine);
	std::vector<uint8_t> matching = std::move(ReflectorParser::parseNumbers(currentLine));
	return Reflector(std::move(matching));
}

void ReflectorParser::serialize(const Reflector &reflector, std::ostream &dst)
{
	dst << ReflectorParser::serializeArray(reflector.matching) << "\n";
}
