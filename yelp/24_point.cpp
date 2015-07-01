#include "basic.h"
bool dfs(vector<double> &nums,double target){
    if(nums.size() == 1 && nums[0] == target)
        return true;
    int size = nums.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            double a = nums[i];
            double b = nums[j];
            vector<double> tmp = nums;
            nums.erase(nums.begin()+i);
            nums.erase(nums.begin()+j-1);
            for(int k=0;k<6;k++){
                switch(k){
                    case 0:
                        nums.push_back(a+b);
                        break;
                    case 1:
                        nums.push_back(a-b);
                        break;
                    case 2:
                        nums.push_back(b-a);
                        break;
                    case 3:
                        nums.push_back(a*b);
                        break;
                    case 4:
                        nums.push_back(a/b);
                        break;
                    case 5:
                        nums.push_back(b/a);
                        break;
                }
                if(dfs(nums,target)) return true;
                nums.pop_back();
            }
            nums = tmp;
        }
    }
    return false;
}

int main(){
	double x[] = {1,1,1,1};
	int len = 4;
	//vector<int> nums = getVector(x,len);
    vector<double> nums;
    for(int i=0;i<len;i++){
        nums.push_back(x[i]);
    }
    vector<string> res;
    double target = 42;
	print(dfs(nums,target));
    //print(res);
}