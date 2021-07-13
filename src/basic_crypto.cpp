#include "../include/basic_crypto.hpp"

using namespace std;

string scytale(string entry, unsigned int width){
    string res = "";
    string entryBis = entry;
    unsigned int widthModulo = width;

    for(unsigned int w = 0; w < width; w++){
        vector<unsigned int> checkList(entryBis.size(), 0);
        for(int i = 0; i<(int)entryBis.size(); i++){
            if(i%widthModulo==0){
                checkList[i]=1;
            }
        }
        string tmp =""; 
        for(int i = 0; i<(int)checkList.size(); i++){
            if(checkList[i]==1){
                res+=entryBis[i];
            }
            else{
                tmp+=entryBis[i];
            }

        }
        entryBis=tmp;
        widthModulo--;
        checkList.clear();
    }
    return res;
}
