#include "../include/modular_arithmetics.hpp"
#include "../include/basics_arithmetics.hpp"

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

int modDivide(int a, int b, int m) 
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
bool isCongruent(int x, int y, int modulo){
    return (x%modulo == y%modulo) ? 0 : 1;
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
