#include <vector>
#include <cmath>


using namespace std;

unsigned int modPow(unsigned int number, unsigned int exponential, unsigned int modulo);
unsigned int modInverse(unsigned int a, unsigned int modulo);
bool isCongruent(int x, int y, int modulo);
unsigned int chinese_remainder(vector<unsigned int> ak, vector<unsigned int> nk);
