#include "basic.h"
vector<vector<int> > threeSum(vector<int> &nums) {
    // write your code here
    sort(nums.begin(),nums.end());
    int size = nums.size();
    vector<vector<int>> res;
    for(int i=0; i<size;i++){
        int target = nums[i];
        int a = i+1;
        int b = size-1;
        while(a<b){
            int value = nums[a] + nums[b] +nums[i];
            if( value == 0){
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[a]);
                tmp.push_back(nums[b]);
                //sort(tmp.begin(),tmp.end());
                res.push_back(tmp);
                a++;
                b--;
                //防止重复
                while(a<b && tmp[1] == nums[a]) a++;
                while(a<b && tmp[2] == nums[b]) b--; 
            }
            else{
                if(value < 0)
                    a++;
                else
                    b--;
            }
        }
        //第一个数字应该如何处理也应该注意到
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
    }
    //sort(res.begin(),res.end());
    //res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}

int main(){
	int x[] = {-1,0, 1, 2, -1, -4};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);
	print(threeSum(nums));
}