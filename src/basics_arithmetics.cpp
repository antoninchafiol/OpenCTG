#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../include/basics_arithmetics.hpp"

using namespace std;
//First occurence of functions (created at the start of the project)

int pgcd(int a, int b){
    if(a<b){
        int c = a;
        a = b;
        b = c;
    }
    return (b==0) ? a : pgcd(b, a%b);
}


vector<int> bezout_coef(int a, int b, int u, int v){
    vector<int> res (2);
    u = 1;
    v = 0;
    
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