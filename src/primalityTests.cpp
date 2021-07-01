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
bool ptFermatd(const u64 n){
    for (u64 a = 1; a < n; a++)
    {
        //printf("numbert: %d \n", mod_pow(a, p-1, p));
        if(mod_pow(a, n-1, n) != 1) {
            return false;
        }
    }
    return true;
    
}

// Real probabilistic Fermat test 
bool ptFermat(const u64 n, const u64 t){
    for (u64 a = 1; a < t; a++)
    {
        u64 k = random_range(2, n-2);
        if(mod_pow(k, n-1, n) != 1) {
            return false;
        }
    }
    return true;
}


bool ptSolStrassd(const u64 n){
    for (u64 a = 1; a < n; a++)
    {
        u64 r = mod_pow(a, ((n-1)/2), n);
        if(r!=1 || r!= n-1){
            return false;
        }
    }
    return true;
}

bool ptSolStrass(const u64 n, const u64 t){
    for (u64 i = 1; i < t; i++)
    {
        u64 a = random_range(2, n-2);
        u64 r = mod_pow(a, ((n-1)/2), n);
        if(r!=1 || r!= n-1){
            return false;
        }
    }
    return true;
}




bool ptMRab_(const u64 n, const u64 t){
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


    for(u64 i = 0; i<t; i++){
        u64 a = random_range(2, n-2);
        u64 y = mod_pow(a,m,n);
        if (y!=1 && y != n-1)
        {
            u64 j = 1;
            while (j<=s-1 && y!= n-1)
            {
                y = mod_pow(y,2,n);
                if(y==1){
                    return false;
                }
                j+=1;
            }
            if(y!= n-1){
                return false;
            }
            
        }
        
    }
    return true;
}

bool ptAKS(const u64 n, const u64 t){
    return 0;
}