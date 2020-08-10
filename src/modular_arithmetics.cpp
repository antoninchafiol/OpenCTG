#include "../include/modular_arithmetics.hpp"

unsigned int powm(unsigned int number, unsigned int exponential, unsigned int modulo){
    unsigned int res = 1;
    number %= modulo;

    while(exponential>0){
        if(exponential & 1)
            res= (res*number) % modulo;
        exponential = exponential >> 1;

        number=(number*number) % modulo;
    }
    return res;
}
