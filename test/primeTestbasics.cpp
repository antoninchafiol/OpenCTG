#include "../include/primalityTests.hpp"
#include <iostream>



int main(int argc, char const *argv[])
{
    if(argc!=3){
        std::cout << "Usage: ./primeTestbasics <p> <n>" << std::endl;
        exit(EXIT_FAILURE);
    }
    const int p = atoi(argv[1]);
    const int n = atoi(argv[2]);
    std::cout << "Number : " << n << std::endl;
    std::cout << "--------- is prime ? ---------" << std::endl;
    std::cout << "Fermatd : "  << std::boolalpha << ptFermatd(p)  << std::endl;
    std::cout << "Fermatp : "  << std::boolalpha << ptFermat(p,n)  << std::endl;
    std::cout << "" << std::endl;
    return 0;
}
