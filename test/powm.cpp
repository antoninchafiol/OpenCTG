#include "../include/modular_arithmetics.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if(argc <= 2){
        std::cout << "Give number, exponential and modulo in parameters" << std::endl;
        exit(1);
    }
    unsigned int a = atoi(argv[1]);
    unsigned int b = atoi(argv[2]);
    unsigned int c = atoi(argv[3]);

    std::cout << powm(a,b,c) << std::endl; 
    return 0;
}
