#include "basic.h"
string longestPalidrome(string &str){
	int size = str.size();
	vector<vector<bool>> check(size,vector<bool>(size,false));
	//bool check[size+1][size+1];
	//fill_n(&check[0][0],(size+1)*(size+1),false);
	int len = 0;
	int start = 0;
	check[0][0] = true;
	// check[i][j] => str i to j is a palidrome or not 
	for(int i=size-1;i>=0;i--){
		for(int j=i;j<=size;j++){
			check[i][j] = (j-i<2 ||check[i+1][j-1]) && (str[j] == str[i]);
			if(check[i][j]){
				if(len < j-i+1){
					len = j-i+1;
					start = i;
				}
			}
		}
	}
	print(check);
	return str.substr(start,len);
}

int main(){
	string str = "abcdzdcab";
	print(longestPalidrome(str));
}