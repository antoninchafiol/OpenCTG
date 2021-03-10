#include "../include/primalityTests.hpp"
#include "../include/arithmetics.hpp"
#include <stdio.h>
#include <random>
/*
*   In these tests, all values is in u64, u64 = uint_64_t (64 bits) and some 
*   big numbers can overflow the memory, this will be changed in the future 
*   to admit bigger numbers.
*   Antonin Chafiol <antonin.chafiol@protonmail.com>
*/

// Determinist Fermat test
bool ptFermatd(const u64 p){
    for (u64 a = 1; a < p; a++)
    {
        //printf("numbert: %d \n", modPow(a, p-1, p));
        if(modPow(a, p-1, p) != 1) {
            return false;
        }
    }
    return true;
    
}

// Real probabilistic Fermat test 
bool ptFermat(const u64 p, const u64 n){
    for (u64 a = 1; a < n; a++)
    {
        u64 k = (rand() % p) + 1;
        if(modPow(k, p-1, p) != 1) {
            return false;
        }
    }
    return true;
}


bool ptSolStrassd(const u64 p){
    for (u64 a = 1; a < p; a++)
    {
        u64 r = modPow(a, ((p-1)/2), p);
        if(r!=1 || r!= p-1){
            return false;
        }
    }
    return true;
}

bool ptSolStrass(const u64 p, const u64 n){
    for (u64 i = 1; i < n; i++)
    {
        u64 a = (rand() % p) + 1;
        u64 r = modPow(a, ((p-1)/2), p);
        if(r!=1 || r!= p-1){
            return false;
        }
    }
    return true;
}




bool ptMRab_(const u64 t, const u64 n){
    if(n<3 && t<1){
        cout << "Bad parameters" << endl;
        return(false);
    }
    // printf("N == %d\n",n);
    // Computing s and m as n-1 = m*2^s
    u64 s = 0;
    u64 m = 0;
    bool isChanged = false;
    for(u64 i = 1; i<n; i++){
        u64 power = (u64)pow(2, i);
        for(u64 j = 1;j<n; j++){
            if(j%2==1 && power*j == n-1){
                s=i;
                m=j;
                isChanged=true;
            }
        }
    }
    if(isChanged==false){
        return false;
    }

    for (u64 i = 0; i < t; i++) // Number of tries 
    {
        u64 a = (rand() % (n-3+1)) + 2;
        // printf("A=%d\n",a);
        u64 r = modPow(a, m, n); //First test
        // printf("First Test = %d \n", fstTest);
        if (r == 1){
            return true;
        }
        for (u64 k = 0; k <= s; k++)
        {   
            u64 secTest = modPow(a, modPow(2,k,n)*m,n);
            // printf("Second Test = %d\n", secTest);
            if(secTest == (u64)n-1){
                return true;
            }
        }
    }
    return false;
}