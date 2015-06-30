// return the longetst substr without repeated chars
//
#include "basic.h"
int lengthOfLongestSubstring(string str) {
    // write your code here
    // O(n) solution with hashtable
    unordered_map<char,int> m;
    int start = 0;
    int begin = 0;
    int len = 0;
    for(int i=0;i<str.size();i++){
        if(m.find(str[i]) != m.end()){
            start = m[str[i]] + 1;
            m[str[i]] = i;
        }
        else{
            m.insert({str[i],i});
        }
        len = max(len,i-start+1);
    }
    return len;
}
int main(){
	string str = "abcabcbb";
	print(lengthOfLongestSubstring(str));
	return 0;
}
