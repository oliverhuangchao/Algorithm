#include "basic.h"
bool isInterleave(string s1, string s2, string s3) {
	string tmp = s1+s2;
	string tmp2 = s3;
	sort(tmp.begin(), tmp.end());
	sort(tmp2.begin(), tmp2.end());
	if(tmp != tmp2)  return false; 
	int l1 = s1.size();
	int l2 = s2.size();
	int l  = s3.size();
	if(l1 == 0) 
		return (s2 == s3);
	if(l2 == 0) 
		return (s1 == s3);
	return isInterleave(s1.substr(0,l1-1),s2,s3.substr(0,l-1)) || isInterleave(s1,s2.substr(0,l2-1),s3.substr(0,l-1));
}

int main(){
	string s1 = "ab";
	string s2 = "cd";
	string s3 = "acdb";
	cout<<isInterleave(s1,s2,s3)<<endl;
}
