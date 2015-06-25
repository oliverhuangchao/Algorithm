// given a sentense and reverse its words order
// example:
// input: hello world chaoh
// output: chaoh world hello
void reverseword(string &x,int a,int b){
	char tmp;
	while(a<b){
		tmp = x[a];
		x[a] = x[b];
		x[b] = tmp;
		a++;
		b--;
	}
	return;
}
int main(){
	//string x;
	char a[128];
	cin.getline(a,sizeof(a));
	string str(a);
	reverseword(str,0,str.size()-1);
	int start = 0;
	for(int i=0;i<str.size();i++){
		if(str[i] == ' '){
			reverseword(str,start,i-1);
			start = i+1;
		}
	}
	reverseword(str,start,str.size()-1);
	cout<<str<<endl;
	return 0;
}
