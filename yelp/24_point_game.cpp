#include "basic.h"
bool dfs(vector<double> &nums,double target,vector<string>& res){
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
                        res.push_back(to_string(a)+"+"+to_string(b));
                        break;
                    case 1:
                        nums.push_back(a-b);
                        res.push_back(to_string(a)+"-"+to_string(b));
                        break;
                    case 2:
                        nums.push_back(b-a);
                        res.push_back(to_string(b)+"-"+to_string(a));
                        break;
                    case 3:
                        nums.push_back(a*b);
                        res.push_back(to_string(a)+"*"+to_string(b));
                        break;
                    case 4:
                        nums.push_back(a/b);
                        res.push_back(to_string(a)+"/"+to_string(b));
                        break;
                    case 5:
                        nums.push_back(b/a);
                        res.push_back(to_string(b)+"/"+to_string(a));
                        break;
                }
                if(dfs(nums,target,res)) return true;
                nums.pop_back();
                res.pop_back();
            }
            nums = tmp;
        }
    }
    return false;
}

int main(){
	double x[] = {1,2,3,6};
	int len = 4;
	//vector<int> nums = getVector(x,len);
    vector<double> nums;
    for(int i=0;i<len;i++){
        nums.push_back(x[i]);
    }
    vector<string> res;
    double target = 42;
	print(dfs(nums,target,res));
    print(res);
    //print(res);
}