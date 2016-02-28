#include "parser.hpp"
#include <sstream>
#include <climits>
#include <stdexcept>



std::vector<uint8_t> Parser::parseNumbers(const std::string &src)
{
	std::istringstream lineStream(src);
	std::vector<uint8_t> matching;

	while(lineStream.good())
	{
		std::string current_s;
		lineStream >> current_s;
		if(current_s.empty())
		{
			break;
		}

		const uint32_t current = std::stoul(current_s);
		if(current > UCHAR_MAX)
		{
			throw std::runtime_error("Incorrect rotor value: " + std::to_string(current));
		}
		matching.push_back(static_cast<uint8_t>(current));
	}

	return matching;
}

std::string Parser::serializeArray(const std::vector<uint8_t> &src)
{
	std::ostringstream stream;
	for(const uint8_t value : src)
	{
		stream << static_cast<uint32_t>(value) << " ";
	}
	return stream.str();
}
