#include <iostream>
#include "../include/basics_arithmetics.hpp"

using namespace std;
int main(int argc, char const *argv[])
{    
    if(argc<2){
        cout << "Usage: ./crypt <parameters>" << endl;
    }
    else{
        int a = pgcd(794, 1356);
        cout << a << endl;

    } 
    return 0;
}
