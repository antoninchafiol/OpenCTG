#include <iostream>
#include "../include/modular_arithmetics.hpp"
#include "../include/basics_arithmetics.hpp"


int main(int argc, char const *argv[])
{
    if (argc<3)
    {
        std::cout << "Usage : ./bezoutc x y " << std::endl;
        exit(EXIT_FAILURE);
    }
    unsigned int x = atoi(argv[1]);
    unsigned int y = atoi(argv[2]);
    std::cout << x << std::endl;
    if (x < y){
        unsigned int tmp = y;
        y = x;
        x = tmp;
    }
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    printf("DEBUG\n");
    vector<int> bCoeff_coef = bCoeff(x,y);
    printf("u : %d | v: %d \n", bCoeff_coef[0], bCoeff_coef[1]);
    return 0;
}
