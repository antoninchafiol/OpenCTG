#include "../include/primalityTests.hpp"
#include "../include/arithmetics.hpp"
#include <stdio.h>
#include <random>
// Determinist Fermat test
bool ptFermatd(const int p){
    for (int a = 1; a < p; a++)
    {
        //printf("numbert: %d \n", modPow(a, p-1, p));
        if(modPow(a, p-1, p) != 1) {
            return false;
        }
    }
    return true;
    
}

// Real probabilistic Fermat test 
bool ptFermat(const int p, const int n){
    for (int a = 1; a < n; a++)
    {
        int k = (rand() % p) + 1;
        if(modPow(k, p-1, p) != 1) {
            return false;
        }
    }
    return true;
}


bool ptSolStrassd(const int p){
    for (int a = 1; a < p; a++)
    {
        int r = modPow(a, ((p-1)/2), p);
        if(r!=1 || r!= p-1){
            return false;
        }
    }
    return true;
}

bool ptSolStrass(const int p, const int n){
    for (int i = 1; i < n; i++)
    {
        int a = (rand() % p) + 1;
        int r = modPow(a, ((p-1)/2), p);
        if(r!=1 || r!= p-1){
            return false;
        }
    }
    return true;
}





void ptMRab_(int a){

}