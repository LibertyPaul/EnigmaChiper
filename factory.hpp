#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <istream>

class Factory
{
    std::istream &srcStream;
public:
    Factory(std::istream &filePath);
    ~Factory();


};

#endif // FACTORY_HPP
