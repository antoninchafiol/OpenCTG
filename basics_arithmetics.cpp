#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "basics_arithmetics.hpp"

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

vector<int> bCoef(int a,  int b){
    vector<int> res (3);
    int r = a, rp = b, u=1, v=0, up= 0, vp = 1;
    while (rp!=0)
    {
        int q = r/rp;
        int rs = r, us = u, vs = v;
        r = rp;
        u = up;
        v = vp;
        rp = rs - q*r;
        up = us - q*up;
        vp = vs - q*vp;
    }
    res[0] = r;
    res[1] = u;
    res[2] = v;
    return res; 
}

bool isPrime(int a){
    return true;
}

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
    for (int i = 0; i < res2.size(); i++)
    {
        if(res2[i]!=-1){
            res.push_back(res2[i]);
        }
    } 
    return res;
}