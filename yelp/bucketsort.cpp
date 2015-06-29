// given a sentense and reverse its words order
// example:
// input: hello world chaoh
// output: chaoh world hello
#include "basic.h"
int main(){
	int size;
	cin>>size;
	vector<pair<string,int>> res(size,make_pair("",0));
	for(int i=0;i<size;i++){
		cin>>res[i].first>>res[i].second;
	}
	vector<vector<pair<string,int>>> z(5,vector<pair<string,int>>());
	for(int i=0;i<size;i++){
		z[res[i].second].push_back(res[i]);
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<z[i].size();j++)
			cout<<z[i][j].first<<'\t'<<z[i][j].second<<endl;
	}
	return 0;
}

