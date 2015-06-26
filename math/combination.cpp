#include "basic.h"
// math problem get the comination number of C(X,Y), choose x's elemesnts from y groups without order
// math problem get the arrange number of A(x,y), choose x's elements from y groups
int multi(int y){
	int res = 1;
	for(int i=1;i<=y;i++)
		res *= i;
	return res;
}
int arrange(int x,int y){ // x < y
	int res = 1;
	for(int i=y;i>=(y-x);i--)
		res *= i;
	return res;
}

int combination(int x,int y){ // x < y
	return arrange(x,y)/multi(x);
}