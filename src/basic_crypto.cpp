#include "../include/basic_crypto.hpp"

using namespace std;

string scytale_enc(string entry, unsigned int width){
    string res = "";
    cout << entry << endl;
    vector<unsigned int> checkList(entry.size());
    fill(checkList.begin(),checkList.end(), 0);

    for(int j = 0; j < width; j++){   
        for(int i = 0; i<entry.size(); i++){
            if(i%width==0){
                cout << entry[i] << endl;
                res+=entry[i];
                checkList[i]=1;
            }
        }
        res+=" ";
        for(int i = 0; i<entry.size();i++){
            if(checkList[i]==1){
                entry.erase(i);
            }
        }
        width--;
        cout << entry << endl;
    }
    // "shifter" la string de <width>+1 éléments
    cout << res << endl;    
    return res;
}
string scytale_dec(string entry, unsigned int width){
    return "";
}