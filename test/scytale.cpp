#include <iostream>
#include"../include/basic_crypto.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 4){
        cout << "Usage : ./scytale <sentence> <width> " << endl;
        exit(EXIT_FAILURE);
    }

    string plaintext = argv[2];
    unsigned int n = atoi(argv[3]);
    string encrypted = scytale(plaintext, n);
    string decrypted = scytale(encrypted, n);
    cout << "Plaintext: "<< plaintext << endl << "Encrypted text: " << encrypted << endl <<"Decrypted text: " << decrypted << endl; 
    return 0;
}