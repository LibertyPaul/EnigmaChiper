
#include "rotorfactory.hpp"
#include "reflectorfactory.hpp"
#include <iostream>


using namespace std;

int main()
{
	RotorFactory rf("./rotors.txt", 5);
	rf.run();

	ReflectorFactory reflectorFactory("./reflector.txt");
	reflectorFactory.run();
}

