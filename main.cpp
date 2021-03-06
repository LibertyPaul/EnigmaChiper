
#include "rotorfactory.hpp"
#include "reflectorfactory.hpp"
#include "enigmamachine.hpp"
#include <iostream>
#include <fstream>
#include <climits>


void man(const std::string &progName)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "\t" << progName << " --create-rotors <rotors file path> <rotors count>" << std::endl;
	std::cout << "\t" << progName << " --encrypt <src file path> <dst file path> <rotors file path> <key[0-255]>" << std::endl;
	std::cout << std::endl;
}

int main(int argc, const char **argv)
{
	const std::string progName(argv[0]);

	if(argc < 2)
	{
		man(progName);
		return -1;
	}

	const std::string mode(argv[1]);
	if(mode == "--create-rotors")
	{
		if(argc < 4)
		{
			man(progName);
			return -1;
		}

		const std::string rotorsFilePath(argv[2]);
		const std::string rotorsCount_s(argv[3]);
		const size_t rotorsCount = std::stoul(rotorsCount_s);


		RotorFactory rf(rotorsFilePath);
		rf.regenerate(rotorsCount);
	}
	else if(mode == "--encrypt")
	{
		if(argc < 6)
		{
			man(progName);
			return -1;
		}

		const std::string srcFilePath(argv[2]);
		const std::string dstFilePath(argv[3]);
		const std::string rotorsFilePath(argv[4]);

		std::vector<uint8_t> key;
		for(int i = 5; i < argc; ++i)
		{
			const std::string currentKeyValue_s(argv[i]);
			size_t tmp = std::stoul(currentKeyValue_s);
			if(tmp > 255)
			{
				man(progName);
				return -1;
			}
			key.push_back(static_cast<uint8_t>(tmp));
		}


		RotorFactory rf(rotorsFilePath);
		std::vector<Rotor> rotors = std::move(rf.read());

		Reflector reflector = ReflectorFactory().getReflector();

		EnigmaMachine enigmaMachine(std::move(rotors), std::move(reflector));
		enigmaMachine.setup(key);



		std::ifstream src(srcFilePath, std::ios_base::binary);
		std::ofstream dst(dstFilePath, std::ios_base::binary | std::ios_base::trunc);

		while(true)
		{
			uint8_t srcSymbol;
			src.read(reinterpret_cast<char *>(&srcSymbol), sizeof(srcSymbol));
			if(src.good() == false){
				break;
			}

			uint8_t dstSymbol = enigmaMachine.encrypt(srcSymbol);
			dst.write(reinterpret_cast<char *>(&dstSymbol), sizeof(dstSymbol));
		}
		return 0;
	}
	else
	{
		man(progName);
		return -1;
	}
}






