// return the longetst substr without repeated chars
//
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
        /*if(len < i-start+1){
            len = i-start+1;
            begin = start;
        }*/
        len = max(len,i-start+1);
    }
    return len;
}