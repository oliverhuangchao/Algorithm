 #include "basic.h"
int main(){
	string x;
	while(1){
		cin>>x;
		if(x == "q")
			break;
		unordered_map<char,int> m;
		int check = 0;
		for(int i=0;i<x.size();++i){
			if(m.find(x[i]) != m.end())
				++m[x[i]];
			else
				m.insert({x[i],1});
		}
		for(auto each : m){
			if(each.second % 2 == 1)
				++check;
		}
		if(check < 2) cout<<"true";
		else cout<<"false";
		cout<<endl;
	}

	return 0;
}
