#include <iostream>
#include"../include/arithmetics.hpp"


int main(int argc, char const *argv[])
{
    unsigned int sise = argc;
    if (argc<3 || (sise-1)%2 !=0 )
    {
        std::cout << "Usage : ./chinese a1 n1 .... " << std::endl;
        exit(EXIT_FAILURE);
    }
    vector<unsigned int> ak;
    vector<unsigned int> nk;
    for (unsigned int i = 1; i < sise; i++)
    {
        if(i%2==0){
            nk.push_back(atoi(argv[i]));
        }
        else{
            ak.push_back(atoi(argv[i]));   
        }
    }
    unsigned int res = chinese_remainder(ak,nk);
    cout << "Unique solution :  " << res << endl;
    return 0;
}
