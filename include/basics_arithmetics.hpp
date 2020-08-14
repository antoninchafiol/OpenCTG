#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

unsigned int pgcd(unsigned int a, unsigned int b);
vector<unsigned int> bezout_coef(unsigned int a, unsigned int b);
int* decompose(int n);
std::vector<int> generate_prime(int max);
bool isPrime(int a);