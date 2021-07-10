#include "../include/basic_crypto.hpp"

using namespace std;

string scytale_enc(string entry, unsigned int width){
    char checkcharlist[entry.size()];
    for(int i = 0; i<entry.size(); i++){
        checkcharlist[i]=0;
    }
    for(int i =0; i<entry.size(); i++){
        if(i%2==0){
            cout << entry[i] << endl;
            checkcharlist[i]=1;
        }
    }
    return "";
}
string scytale_dec(string entry, unsigned int width){
    return "";
}