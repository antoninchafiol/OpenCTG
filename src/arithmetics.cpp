#include "../include/arithmetics.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../include/arithmetics.hpp"

//First occurence of functions (created at the start of the project)


vector<int> bCoeff(unsigned int a, unsigned int b){
    vector<int> res (2);
    unsigned int r = a, u = 1, v = 0, rp = b, up = 0, vp = 1, q, rs, us, vs;

    while (rp != 0)
    {
        q = r/rp;
        rs = r; us = u; vs = v;
        r = rp; u = up; v = vp;
        rp = rs - q * rp;
        up = us - q * up;
        vp = vs - q * vp;
    }
    res[0] = u;
    res[1] = v;
    return res;
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
    for (int i = 0; i < (int)res2.size(); i++)
    {
        if(res2[i]!=-1){
            res.push_back(res2[i]);
        }
    } 
    return res;
}


unsigned int pgcd(unsigned int a, unsigned int b){
    if(a<b){
        unsigned int c = a;
        a = b;
        b = c;
    }
    return (b==0) ? a : pgcd(b, a%b);
}



// doesn't optimized (Around 2^x complexity)


unsigned int modPow(unsigned int number, unsigned int exponential, unsigned int modulo){
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

unsigned int modDivide(int a, int b, int m) 
{ 
    int res = 0;
    a = a % m; 
    int inv = modInverse(b, m); 
    if (inv == -1) 
       cout << "Division not defined"; 
    else
       res = (inv * a) % m; 

    return res;
} 
  

unsigned int modInverse(unsigned int a, unsigned int modulo){
    unsigned int res = 0;
    a = a%modulo; 
    for (unsigned int x=1; x<modulo; x++) 
       if ((a*x) % modulo == 1){
           res = x;
           return res;
       }
    return res;
}
unsigned int chinese_remainder(vector<unsigned int> ak, vector<unsigned int> nk){
    bool bIscoprime = true;
    unsigned int k_size = nk.size();
    // Test if all nk are two by two coprimal
    for (unsigned int i = 0; i < k_size; i++)
    {
        if(i+1 > nk.size()-1)
            break;
        if(pgcd(nk[i], nk[i+1]) != 1){
            bIscoprime = false;
        }
    }
    if(bIscoprime!=true){
        cout << "All number of the nk vector isn't two by two prime " << endl;
        exit(EXIT_FAILURE); 
    }
    // create N et Nk using all nk
    unsigned int N = 1;
    for (unsigned int i = 0; i < k_size; i++)
    {
        N *= nk[i];
    }
    vector<unsigned int> N_k;
    for (unsigned int i = 0; i < k_size; i++)
    {
        N_k.push_back(N/nk[i]);
    }
    // Creation of the uk
    vector<unsigned int> uk;
    for (unsigned int i = 0; i < k_size; i++)
    {
        vector<int> temp_u = bCoeff(N_k[i], nk[i]);
        uk.push_back(temp_u[0]);
    }

    int res =0;
    for (unsigned int i = 0; i < k_size; i++)
    {
        res += uk[i]*N_k[i]*ak[i];
    }
    res =  (int)remainder((double)res, (double)N);
    cout << "Unique solution: x = " << res << " mod " << N << endl;
    return res;  
        
}

bool bisCongruent(int x, int y, int modulo){
    return (x%modulo == y%modulo) ? 0 : 1;
}