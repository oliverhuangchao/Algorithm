#include "basic.h"
inline static bool isPalidrome(const string x){
    int i = 0;
    int j = x.size()-1;
    while(i<j){
        if(x[i] != x[j]) return false;
        i++;
        j--;
    }
    return true;
}
void dfs(vector<vector<string>> &result, vector<string> &path, const string &s,int start,int target){
    if(start == target){
        result.push_back(path);
        return;
    }
    for(int i=1;i<target-start;i++){
        string tmp = s.substr(start,i);
        if(isPalidrome(tmp)){
            path.push_back(tmp);
            dfs(result,path,s,start+i,target);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    dfs(result,path,s,0,s.size());
    return result;
}

int main(){
	string s = "aab";
	vector<vector<string>> r = partition(s);
	print(r);
}