#include "../include/basic_crypto.hpp"

using namespace std;

string scytale_enc(string entry, unsigned int width){
    string res = "";
    string entryBis = entry;

    unsigned int widthModulo = width;
    for(int j = 0; j < width; j++){   
        vector<unsigned int> checkList(entry.size()-res.size(), 0);
        for(int i = 0; i<entry.size(); i++){
            if(i%widthModulo==0){
                cout << entryBis[i] << endl;
                checkList[i]=1;
            }
        }
        string tmp =""; 
        for(int i = 0; i<checkList.size(); i++){
            cout << checkList[i] << " " ;
            if(checkList[i]==1){
                res+=entryBis[i];
            }
            else{
                tmp+=entryBis[i];
            }
        cout << entryBis  << " " << res << endl;

        }
        entryBis=tmp;
        widthModulo--;
        checkList.clear();
        cout << entry << endl;
    }
    // "shifter" la string de <width>+1 éléments
    cout << res << endl;    
    return res;
}
string scytale_dec(string entry, unsigned int width){
    return "";
}