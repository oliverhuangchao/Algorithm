#include "basic.h"
string longestPalidrome(string &str){
	int size = str.size();
	bool check[size+1][size+1];
	fill_n(&check[0][0],(size+1)*(size+1),false);
	int len = 0;
	int start = 0;
	check[0][0] = true;
	for(int i=0;i<=size;i++){
		for(int j=i;j<=size;j++){
			if(i==j)
				check[i][j] = true; 
			else if(j-i == 1)
				check[i][j] = s[j] == s[i];
			else
				check[i][j] = check[i+1][j-1] && (s[j] == s[i]);
			if(check[i][j]){
				if(len < j-i+1){
					len = j-i+1;
					start = i;
				}
			}
		}
	}
	return str(start,len);
}

int main(){
	string str = "";
	print(longestPalidrome(str));
}