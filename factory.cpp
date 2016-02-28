#include "factory.hpp"
#include <fstream>
#include <stdexcept>

Factory::Factory(const std::string &filePath): filePath(filePath)
{

}

Factory::~Factory()
{

}

void Factory::run()
{
	std::fstream rotorsFile(this->filePath, std::ios_base::in | std::ios_base::binary);
	if(rotorsFile.is_open())
	{
		this->read(rotorsFile);
	}
	else
	{
		rotorsFile.open(this->filePath, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
		if(rotorsFile.is_open() == false)
		{
			throw std::runtime_error("Can't create rotors file");
		}
		this->generate();
		this->write(rotorsFile);
	}
}
