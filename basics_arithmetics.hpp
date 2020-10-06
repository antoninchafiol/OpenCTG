#include <vector>
using namespace std; 
int pgcd(int a, int b);
int* bezout_coef(int a, int b);
vector<int> bCoef(int a,  int b);
int* decompose(int n);
vector<int> generate_prime(int max);
bool isPrime(int a);
unsigned int chinese_remainder(vector<int> ak, vector<int> nk)