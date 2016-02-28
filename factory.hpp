#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <istream>
#include <ostream>

class Factory
{
	std::string filePath;

	virtual void read(std::istream &src) = 0;
	virtual void generate() = 0;
	virtual void write(std::ostream &dst) const = 0;
public:
	Factory(const std::string &filePath);
	virtual ~Factory();

	void run();

};

#endif // FACTORY_HPP
