#include <iostream>
#include"../include/basic_crypto.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 4){
        cout << "Usage : ./scytale <enc/dec> <sentence> <number> " << endl;
        exit(EXIT_FAILURE);
    }

    string func = argv[1];
    string sentence = argv[2];
    unsigned int n = atoi(argv[3]);
    if(func.compare("enc")==0){
        scytale_enc(sentence,n);
    }
    else if(func.compare("dec")==0){
        scytale_dec(sentence, n);
    }
    cout << "cout : "<< func << " " << sentence << " " << n << endl; 
    return 0;
}
