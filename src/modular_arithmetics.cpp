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

bool isCongruent(int x, int y, int modulo){
    return (x%modulo == y%modulo) ? 0 : 1;
}

unsigned int modular_inverse(unsigned int a, unsigned int modulo){
    a = a%modulo; 
    for (int x=1; x<modulo; x++) 
       if ((a*x) % modulo == 1) 
          return x; 
}

unsigned int chinese_remainder(vector<vector<int>> input){
    int res = 0;
}
