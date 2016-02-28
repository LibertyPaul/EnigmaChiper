#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

class Parser
{
protected:
	static std::vector<uint8_t> parseNumbers(const std::string &src);
	static std::string serializeArray(const std::vector<uint8_t> &src);
};

#endif // PARSER_HPP
