
#include "rotorfactory.hpp"
#include "reflectorfactory.hpp"
#include "enigmamachine.hpp"
#include <iostream>
#include <fstream>
#include <climits>


using namespace std;





void testRotor(){
	RotorFactory rf("/tmp/rotors");
	std::vector<Rotor> rotors = rf.regenerate(1);

	for(size_t i = 0; i < UCHAR_MAX; ++i)
	{
		uint8_t src = static_cast<uint8_t>(i);
		uint8_t enc = rotors.at(0).transformForward(src);
		uint8_t dec = rotors.at(0).transformBackward(enc);

		if(src != dec)
		{
			std::cout << "FAIL" << std::endl;
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void testReflector(){
	std::vector<Rotor> rotors = RotorFactory("/tmp/rotors").regenerate(1);
	Reflector reflector = ReflectorFactory().getReflector();

	for(size_t i = 0; i < UCHAR_MAX; ++i)
	{
		const uint8_t src1 = static_cast<uint8_t>(i);
		const uint8_t enc1 = rotors.at(0).transformForward(src1);
		const uint8_t ref1 = reflector.transform(enc1);
		const uint8_t dec1 = rotors.at(0).transformBackward(ref1);

		const uint8_t src2 = dec1;
		const uint8_t enc2 = rotors.at(0).transformForward(src2);
		const uint8_t ref2 = reflector.transform(enc2);
		const uint8_t dec2 = rotors.at(0).transformBackward(ref2);

		if(src1 != dec2)
		{
			std::cout << "FAIL" << std::endl;
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;

}









void man(const std::string &progName)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "\t" << progName << " --create-rotors <rotors file path> <rotors count>" << std::endl;
	std::cout << "\t" << progName << " --encrypt <src file path> <dst file path> <rotors file path> <key[0-255]>" << std::endl;
	std::cout << std::endl;
}

int main(int argc, const char **argv)
{
	testReflector();
	return 0;

	argv[0] = "enigma";
	argv[1] = "--encrypt";
	argv[2] = "rotors.txt";
	argv[3] = "encrypted.txt";
	argv[4] = "rotors.txt";
	argv[5] = "12";
	argv[6] = "53";
	argv[7] = "21";
	argv[8] = "42";
	argc = 9;

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


		while(src.eof() == false)
		{
			uint8_t srcSymbol;
			src.read(reinterpret_cast<char *>(&srcSymbol), sizeof(srcSymbol));
			uint8_t dstSymbol = enigmaMachine.encrypt(srcSymbol);
			dst.write(reinterpret_cast<char *>(&dstSymbol), sizeof(dstSymbol));
		}
	}
	else
	{
		man(progName);
		return -1;
	}
}






