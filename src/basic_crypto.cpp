#include "../include/basic_crypto.hpp"

using namespace std;

string scytale_enc(string entry, unsigned int width){
    string res = "";
    cout << entry << endl;
    char checkcharlist[entry.size()];

    unsigned int lineNumber = (unsigned int)entry.size()/width;
    unsigned int count = 0;
    for(int j = 0; j < width; j++){   
        for(int i = 0; i<entry.size(); i++){
            if(i%width==0){
                if(j==width-1){
                    continue;
                }
                cout << entry[i] << endl;
                res+=entry[i];
            }
            count++;
            cout << i << " " << count << " " << count/3 << endl;
        }
        res+=" ";
        rotate(entry.begin(), entry.begin()+1, entry.end());    
        cout << entry << endl;
    }
    // "shifter" la string de <width>+1 éléments
    cout << res << endl;    
    return res;
}
string scytale_dec(string entry, unsigned int width){
    return "";
}