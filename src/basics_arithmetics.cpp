#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../include/basics_arithmetics.hpp"

using namespace std;
//First occurence of functions (created at the start of the project)

unsigned int pgcd(unsigned int a, unsigned int b){
    if(a<b){
        unsigned int c = a;
        a = b;
        b = c;
    }
    return (b==0) ? a : pgcd(b, a%b);
}


vector<unsigned int> bezout_coef(unsigned int a, unsigned int b){
    vector<unsigned int> res (2);
    unsigned int r = a,  rp = b, u = 1, v = 0, up = 0, vp = 1;
    while (rp != 0)
    {
        unsigned int q = (unsigned int)r/rp;
        unsigned int rs = r, us = u, vs = v, r = rp, u = up, v = vp;
        unsigned int rp = rs - q*rp, up = us - q*up, vp = vs - q*vp;
    }
    res[0] = u;
    res[1] = v;
    return res;
}

bool isPrime(int a){
    return true;
}

// doesn't optimized (Around 2^x complexity)
vector<int> generate_prime(int max){
    max++;
    vector<int> res2 (max);
    for (int i = 0; i < max; i++) res2[i] = i;
    res2[0] = -1;
    
    int k = 2;
    while((k*k)<=max){
        for(int j = k+1; j<max; j++){
            if(res2[j]!=-1 && res2[j]%k == 0){
                res2[j] = -1;
            }
        }
        for (int l = 0; l < max; l++)
        {
            if(res2[l]!=-1){
                k = res2[l];
            }
        }
        
    }
    
    vector<int> res;
    for (int i = 0; i < (int)res2.size(); i++)
    {
        if(res2[i]!=-1){
            res.push_back(res2[i]);
        }
    } 
    return res;
}