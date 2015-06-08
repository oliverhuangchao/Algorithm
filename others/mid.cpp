#include "mid.h"

std::string getString(std::stack<int> x,std::string z){
    int size = x.size();
    for(int i=0;i<size;i++){
        int tmp = x.top();
        z.insert(tmp,1,'.');
        x.pop();
    }
    return z;
}


//------ valid IP------
std::vector<std::string> getValidIP(std::string){
	std::vector<std::string> result;
    std::stack<int> s;
    std::string tmp = x;
    std::string restString;
    int size = x.size();
    for(int i = x.size()-1;i>0;i--){
        if(atoi(x.substr(0,i-0).c_str())>256)
            continue;
        else{
            s.push(i);
            for(int j=x.size()-1;j>i;j--){
                if(atoi(x.substr(i,j-i).c_str())>256)
                    continue;
                else{
                    s.push(j);
                    for(int k=x.size()-1;k>j;k--){
                        if(atoi(x.substr(j,k-j).c_str())>256)
                            continue;
                        else{
                            s.push(k);
                            restString = x.substr(k,size-k);
                            if(atoi(restString.c_str()) < 256){
                                result.push_back(getString(s,x));
                            }
                            s.pop();
                        }
                    }
                    s.pop();
                }
            }
            s.pop();
        }
    }
    return result;
}

//------ 134 ------
//------ gas station ------
int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        std::vector<int> absGas;
        std::vector<int> booleanVector;
        int size = gas.size();
        for(int i=0;i<size;i++){
            absGas.push_back(gas[i]-cost[i]);
            if(absGas[i]>0)
                booleanVector.push_back(1);
            else
                booleanVector.push_back(0);
        }
        for(int i=0;i<size;i++){
            absGas.push_back(gas[i]-cost[i]);
            if(absGas[i]>0)
				booleanVector.push_back(1);
            else
                booleanVector.push_back(0);
        }
        int count = 0;
        int end = size;
        int start = 0;
        for(int i=0;i<2*size;i++){
            count += absGas[i];
            if(count<0){
                count = 0;
                while(booleanVector[i]){
                    i++;
                    if(i>=size*2) return -1;
                }
                start = i;
                end = i + size;
                i--;
            }
            if(i == end-1)
                return start;
        }
        return -1;
    }

// ------ 179 ------
//------ find the laregest number given a list of integer -----
//[3,30,34,5,9] should be 9534330
std::string largestNumber(std::vector<int>& num){
	/*
	int size = num.size();
	if(size==0) return "";
	if(size==1) return std:: to_string(num[0]);
	std::vector<std::string> stringnum;
//	std::vector<int> length;
	std::multimap<int,int,std::greater<int>> newnum;
	int tmpsize = 0;
	std::string tmp;
	int maxsize = 0;
	for(int i=0;i<size;i++){
		tmp = std::to_string(num[i]);
		//length[i] = tmp.size();
		stringnum.push_back(tmp);
		if(maxsize<tmp.size())
			maxsize = tmp.size();
	}
	for(int i=0;i<size;i++){
		tmp = stringnum[i];
		tmpsize = tmp.size();
		tmp = tmp.insert(tmp.size(),maxsize-tmpsize,tmp[0]);
		newnum.insert(std::pair<int,int>(atoi(tmp.c_str()),tmpsize));
	}
	std::multimap<int,int>::iterator ptr = newnum.begin();
	std::string result="";
	for(ptr;ptr!=newnum.end();ptr++){
		tmp = std::to_string(ptr->first);
		result = result.append(tmp.substr(0,ptr->second));
	}
	return result;
	*/
	int size = num.size();
	std::string maxstring = "";
	for(int i=0;i<size;i++){
		if(i==0){
			maxstring = num[0];
			continue;
		}
		else{
//			maxstring = largestNumber(num[i],maxstring);
		}
	}
	return maxstring;
}


//------ 1 ------
//two sum: given a vector of integer and find our two integers such that adding them together will lead to the value we want
//
std::vector<int> twoSum(std::vector<int> &numbers,int target){
	std::vector<int> result;
	std::unordered_map<int,int> z;
	int size = numbers.size();
	for(int i=0;i<size;i++){
		if(z[numbers[i]] != 0){
			if(numbers[i]*2 == target){
				result.push_back(i);
				result.push_back(z[numbers[i]]);
				return result;
				//break;
			}
			else
				z.insert(std::pair<int,int>(numbers[i],i));
		}
		else{
			z.insert(std::pair<int,int>(numbers[i],i));
		}
	}
	std::cout<<z.size()<<std::endl;
	int value;
	for(int i=0;i<size;i++){
		value = target-numbers[i];
		if(z[value] != 0){
			result.push_back(i);
			result.push_back(z[value]);
			return result;
		}
		else{
			z.insert(std::pair<int,int>(target-numbers[i],i));
		}
	}
	return result;
}
//------ 55 ------
//jump game
//using dfs to deal with it
//using dfs, we can get all the path for this sulotions
//acturally we just want to konw the whether or not
bool canJump(int A[],int n){
	std::stack<int> mystack;
	mystack.push(A[0]);
	int step = 0;
	int tmp;
	while(step<n){
		step += mystack.top();
		if(step > n){return true;}
		if(A[step] == 0){
			step -= mystack.top();
			tmp = mystack.top()-1;
			mystack.pop();
			if(tmp == 0){
				while(tmp == 0){
					step -= mystack.top();
					mystack.pop();
					tmp = mystack.top()-1;
				}
			}
			mystack.push(tmp);
		}
		else{
			mystack.push(A[step]);
		}
	}
	return true;
}
// a tricky method to solve this problem
bool canJump2(int A[],int n){
	if(n<2)
		return true;
	int max = 0;
	for(int i=0;i<n-1;i++){
		if(max<i) return false;
		if(max<A[i]+i)
			max = i + A[i];
	}
	if (max>=n-1)
		return true;
	else
		return false;
}

//------ 72 ------
//edit distance

int ldistance(std::string s1, std::string s2){

	s1.insert(0,1,'$');
	s2.insert(0,1,'$');
	int size1 = s1.size();
	int size2 = s2.size();

//	std::vector<std::vector<int>> value(size2,std::vector<int>())
	int** value;
	value = new int* [size1];
	for(int i=0;i<size1;i++){
		value[i] = new int[size2];
	}
	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			value[i][j] = 0;
		}
	}
//	for(int j=0;j<size2;j++){
//		value.push_back();
//	}
/*
	for(int i=0;i<=size1;i++){
		for(int j=0;j<=size2;j++){
			if(i==0 && j==0){
				value[i][j]=0;
				continue;
			}
			if (i == 0 && j!= 0){
				value[i][j]=value[i][j-1];
				continue;
			}
			if (j == 0 && i!= 0){
				value[i][j]=value[i-1][j];
				continue;
			}
			int m;
			m=(s1[i-1]==s2[j-1])?0:1;
			value[i][j]=min3(value[i-1][j-1]+m,value[i-1][j]+1,value[i][j-1]+1);
		}
	}
	return value[size1][size2];
*/
	return getLD(s1,s2,size1-1,size2-1,value);
}


//int getLD(std::string& x, std::string& y,int i,int j,std::vector<std::vector<int>> &value){
int getLD(std::string& x, std::string& y,int i,int j,int **value){
	if(i==0 && j== 0){
		value[0][0]=0;
		return 0;
	}
	if (i == 0 && j!= 0){
		if(value[0][j-1] != 0) return value[0][j-1]+1;
		else return getLD(x,y,0,j-1,value)+1;
	}
	if (j == 0 && i!= 0){
		if(value[i-1][0] != 0) return value[i-1][0]+1;
		else return getLD(x,y,i-1,0,value)+1;
	}

	int m;
	m=(x[i]==y[j])?0:1;
	int a,b,c;
	if(value[i-1][j-1] != 0) a = value[i-1][j-1];
	else a = getLD(x,y,i-1,j-1, value);

	if(value[i-1][j] != 0) b = value[i-1][j];
	else b = getLD(x,y,i-1,j, value);

	if(value[i][j-1] != 0) c = value[i][j-1];
	else c = getLD(x,y,i,j-1, value);

	value[i][j] = min3(a+m,b+1,c+1);
	return value[i][j];
}

inline int min3(int x,int y,int z){
	if(x<=y && x<=z) return x;
	if(y<=x && y<=z) return y;
	if(z<=x && z<=y) return z;
}

