#include "basic.h"
void RadixSort(vector<int> &num){
    vector<vector<int>> bucket(11,vector<int>());
    int len = maxLength(num);
    for(int k=0;k<len;k++){
        for(auto each:num){
            int index = (int)pow(10,k);
            if(each<index) 
                bucket[10].push_back(each);
            else
                bucket[each/index%10].push_back(each);

        }
        num.clear();
        
        for(auto n:bucket[10])
            num.push_back(n);
        
        for(int i = 0;i<10;i++){
            for(auto n:bucket[i]){
                num.push_back(n);
            }
            bucket[i].clear();
        }
        bucket[10].clear();
    }
}
int main(){
    int x[] = {1,3,23,5,2};
    int len = sizeof(x)/sizeof(x[0]);
    vector<int> a = getVector(x,len);
    print(a);
    RadixSort(a);
    print(a);
}