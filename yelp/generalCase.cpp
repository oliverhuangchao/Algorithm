#include "basic.h"
void dfs(vector<string> &result,int step, string &path){
	if(step == path.size()){
		result.push_back(path);
		return;
	}
	if(path[step] >= 97 && path[step] <= 122){
		path[step] -= 32;
		dfs(result,step+1,path);
		path[step] += 32;
		dfs(result,step+1,path);
	}
	else{
		dfs(result,step+1,path);
	}
	return;
}
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i] < 97 && str[i] > 64)
			str[i] += 32;
	}
	//print(str);
	vector<string> res;
	dfs(res,0,str);
	print(res);
	return 0;
}

 
