#include "easy.h"

//------ 38 ------
// count and say
std::string changeString(std::string){
	
}
// ------ 6 ------ 
//------ zigzag ------
std::string ZigConvert(std::string s, int n){
    if(s == ""){
        return s;
    }
    std::string result;
    int size = s.size();
    for(int i=0;i<size;i++){
        switch (i%4){
            case 0:
                result.insert(i/4,0,s[i]);
                break;
            case 1:
                result.insert(i/4+size/4+1,0,s[i]);
                break;
            case 2:
                result.insert(i/4+size/44+2,0,s[i]);
                break;
            case 3:
                result.insert(i/4+size/4*2+1,0,s[i]);
                break;
            default:
                break;
        }
    }
}

// ------ 67 ------
// add binary
// method 1 only the string do the operation
std::string addBinary(std::string x, std::string y){
	std::string result;
	int i,j;
	i = x.size()-1;
	j = y.size()-1;
	bool tmp = false;
	char c1,c2;
	while(i>=0 || j>=0){
		if(i>=0){
			c1 = x[i];
			i--;
		}
		else
			c1 = '0';

		if(j>=0){
			c2 = y[j];
			j--;
		}
		else
			c2 = '0';
		
		if(c1 == '1' && c2 == '1'){
			if(tmp)
				result.insert(0,1,'1');
			else
				result.insert(0,1,'0');
			tmp = true;
			continue;
		}
		if((c1 == '0' && c2 == '1') || (c1 == '1' && c2 == '0')){
			if(tmp){
				result.insert(0,1,'0');
			}
			else
				result.insert(0,1,'1');
			continue;
		}
		if(c1 == '0' && c2 == '0'){
			if(tmp)
				result.insert(0,1,'1');
			else
				result.insert(0,1,'1');
			tmp = false;
			continue;
		}
	}
	if(tmp)
		result.insert(0,1,'1');
	return result;
}

// it depends that this figure is not too long
int binary2Dec(std::string x){
	if(x == "") return 0;
	int size = x.size();
	int result = 0;
	for(int i=0;i<size;i++){
		result += (x[i]-48) * pow(2,size-i-1);
	}
	return result;
}

std::string dec2binary(int x){
	std::string result;
	if(x == 0){
		result.insert(0,1,'0');
		return result;
	}
	if(x == 1){
		result.insert(0,1,'1');
		return result;
	}
	int a;
	while(x>0){
		a = x % 2;
		x = x / 2;
		if(a == 1)
			result.insert(0,1,'1');
		else
			result.insert(0,1,'0');
	}
	return result;
}
// ------ 168 ------
//------ excel sheet label ------
std::string excelColumn(int x){
	//enum excel{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
	if(x == 0) return "";
	char* excel="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string z = "";
	if(x<27){
		z = z.insert(0,1,excel[x-1]);
		return z;
	}
	int a;
	while(x > 0){
		a = x % 26;
		x = x / 26;
		if(a == 0) {
			a = 26;
			x --;
		}
		z = z.insert(0,1,excel[a-1]);
	}
	return z;
}
//------ 8 ------
//string to integer
int String2Integer(const char* x){
	int size = strlen(x);
	int boolean = 1;
	int i=0;
	if(x[0] == '-'){
		boolean = -1;
		i = 1;
	}
	if(x[0] == '+')
		i = 1;
	for(i;i<size;i++){
		if(x[i] != '0')
			break;
	}
	int result = 0;
	for(int j=i;j<size;j++){
		result += pow(10,size-j-1) * (x[j] - 48);
	}
	return result*boolean;
}

//------ 169 ------
//------ majority element -----
int majorityElement(std::vector<int>& num){
	// directly sort without hashtable
	int size = num.size();
	if(size == 1) return num[0];
	std::sort(num.begin(), num.end(), myCompareFunc);
	int tmp = num[0];
	int count = 1;
	int max = 1;
	for(int i=1;i<size;i++){
		if(num[i] == num[i-1])
			count++;
		else{
			count = 1;
		}
		if(max < count){
			max = count;
			tmp = num[i];
		}
	}
	return tmp;
}

bool myCompareFunc(int x,int y){
	return x>y? true:false;
}



//-------20
//topic: valid parentheses
bool  validParentheses(std::string x){
	if(x.size()%2 != 0) return false;// be aware that we need to save space and time as possible as we can
	std::stack<char> y;
	std::string::iterator ptr = x.begin();
	while(ptr!=x.end()){
		if(*ptr =='(' || *ptr == '[' || *ptr=='{'){
			y.push(*ptr);
		}
		else{
			if(y.empty()) return false;
			switch(*ptr){
				case ')':
					if(y.top() != '(')
						return false;
					break;
				case ']':
					if(y.top() != '[')
						return false;
					break;
				case '}':
					if(y.top() != '{')
						return false;
					break;
				default:
					break;
			}
			y.pop();
		}
		ptr++;
	}
	if(y.empty()) return true;
	else return false;
}


//------ 88 ------
//------ merge two sorted array together ------
void mergeTwoArray(int *A,int m,int B[],int n){
	int *a = A;
	int *b = B;
	int *p = A+m;
	int *q = A+m;
	int count = 0;
	while(count<m+n){
		if(*a<=*b || b == nullptr){
			*p = *a;
			*a = *q;
			a++;
			p++;
			q++;
			count++;
			continue;
		}
		if(*a>*b || a == nullptr){
			*p = *b;
			b++;
			p++;
			count++;
			continue;
		}
	}
}
//------ 7 ------
//reverse an integer
int reverseInteger(int x){
	std::string y = std::to_string(x);
	std::string m;
	int i,count;
	int size = y.size();
	count = size - 1;
	if(y[0]=='-'){
		i=1;
		m[0]='-';
	}
	else
		i=0;
	for(i;i<size;i++){
		m[i]=y[count];
		count--;
	}
	return atoi(m.c_str());
}


