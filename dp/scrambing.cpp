#include "basic.h"
bool isScramble(string s1, string s2) {
    int size = s1.size();
    if(size != s2.size()) return false;
    bool table[size+1][size][size];
    fill_n(&table[0][0][0],(size+1)*size*size,false);//注意格式
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            table[0][i][j] = true;
            table[1][i][j] = (s1[i] == s2[j]); 
        }
    }
    for(int n=2;n<=size;n++){
        for(int i = 0;i<size;i++){
            for(int j = 0;j<size;j++){
                for(int k=0;k<n;i++){
                    table[n][i][k] = (table[k][i][j] && table[n-k][i+k][j+k]) || (table[k][i][j+n-k] && table[n-k][i+k][j]);
                    if(tables[n][i][k]) break;
                }
            }
        }
    }
    return table[size][0][0];
}

int main(){
    string s1 = "great";
    string s2 = "aterg";
    cout<<isScramble(s1,s2)<<endl;
}