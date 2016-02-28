#include "rotorparser.hpp"
#include <sstream>


std::vector<Rotor> RotorParser::parse(std::istream &src)
{
	std::vector<Rotor> result;
	while(src.good())
	{
		std::string currentLine;
		std::getline(src, currentLine);
		std::vector<uint8_t> matching = RotorParser::parseNumbers(currentLine);

		if(matching.empty())
		{
			continue;
		}
		Rotor current(std::move(matching));
		result.push_back(std::move(current));
	}
	return result;
}

void RotorParser::serialize(const std::vector<Rotor> &rotors, std::ostream &dst)
{
	for(const Rotor &rotor : rotors)
	{
		dst << RotorParser::serializeArray(rotor.matching) << "\n";
	}
}
