#include "basic.h"
int main(){
	int len_1,len_2;
	cin>>len_1>>len_2;
	unordered_map<int,int> m;
	for(int i=0;i<len_1;i++){
		int key,value;
		cin>>key>>value;
		m.insert({key,value});
	}
	int res = 0;
	for(int i=0;i<len_2;i++){
		int key,value;
		cin>>key>>value;
		if(m.find(key) != m.end())
			res += m[key]*value; 
	}
	cout<<res;
	return 0;
}

 
