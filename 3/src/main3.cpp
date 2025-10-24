#include <iostream>
#include <string>
#include "main3.hpp"
//#define DEBUG

int main()
{
#ifdef DEBUG
    std::cout<< "DEBUG: ...\n";
#endif
        return 0;
}
