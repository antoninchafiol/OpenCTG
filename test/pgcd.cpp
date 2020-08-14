#include <iostream>
#include"../include/basics_arithmetics.hpp"

int main(int argc, char const *argv[])
{
    if (argc<3)
    {
        std::cout << "Usage : ./pgcd a b " << std::endl;
        exit(EXIT_FAILURE);
    }
    unsigned int a = (unsigned int)atoi(argv[1]);
    unsigned int b = (unsigned int)atoi(argv[2]);

    unsigned int pgcd_value = pgcd(a,b);
    std::vector<unsigned int> bezout_coef_value = bezout_coef(a,b);
    
    printf("PGCD: %d\n Identity: u = %d  v = %d", pgcd_value, bezout_coef_value[0], bezout_coef_value[1]);
    
    return EXIT_SUCCESS;
}
