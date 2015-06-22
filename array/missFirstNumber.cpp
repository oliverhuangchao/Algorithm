// find  the missing number in 0 to N
// there will be N numbers, but totally N+1 candidates
// O(n) time and O(1) space to solve this problems
// hint: swap two numbers in the array to achieve this goal
inline void swap(vector<int> &nums,int i){
    int tmp = nums[i];
    nums[i] = nums[tmp];
    nums[tmp] = tmp;
}
int findMissing(vector<int> &nums) {
    // write your code here
    // 根据提示，可以改变数组中数的位置
    int size = nums.size();
    nums.push_back(-1);
    int i=0;
    while(i<=size){
        if(nums[i] == i || nums[i] == -1){
            i++;
            continue;
        }
        else{
            swap(nums,i);
        }
    }
    for(int i=0;i<=size;i++)
        if(nums[i] == -1) return i;
}