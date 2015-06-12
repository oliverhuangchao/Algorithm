
#include "basic.h"
int kSum(vector<int> nums, int k, int target) {
    // wirte your code here
    // dp solution
    sort(nums.begin(),nums.end());
    //print(nums);
    int size = nums.size();
    int maxvalue = max(target,nums.back());
    print(maxvalue);
    int f[size+1][k+1][maxvalue+1];
    fill_n(&f[0][0][0],(size+1)*(k+1)*(maxvalue+1),0);
    //vector<vector<vector<int>>> f(size+1,vector<vector<int>>(k+1,vector<int>(maxvalue+1)));
    f[0][0][0] = 1;
    for(int i=1;i<=size;i++)
        f[i][1][nums[i-1]] = 1;
    for(int t = 0;t<=target;t++){
        for(int j = 0;j <= k;j++){
            for(int i = 0;i <= size; i++){
                if(i == 0 && j !=0 ){f[i][j][t] = 0; continue;}
                if(j == 0 && t == 0){f[i][j][t] = 1; continue;}
                if(i<j){f[i][j][t] = 0; continue;}
                if((t-nums[i-1])<0)
                    f[i][j][t] = f[i-1][j][t];
                else
                    f[i][j][t] = f[i-1][j-1][t-nums[i-1]] + f[i-1][j][t];
               /* if (j == 0 && t == 0) {
                    // select 0 number from i to the target: 0
                    f[i][j][t] = 1;
                } else if (!(i == 0 || j == 0 || t == 0)) {
                    f[i][j][t] = f[i - 1][j][t];
                    if (t - nums[i - 1] >= 0) {
                        f[i][j][t] += f[i - 1][j - 1][t - nums[i - 1]];
                    }
                }*/


            }
        }
    }
    return f[size][k][target];
}
int main(){
    int x[] = {1,3,2,4,5};
    int len = sizeof(x)/sizeof(x[0]);
    vector<int> nums = getVector(x,len);

    //print(nums);
    print(kSum(nums,3,10));
} 
