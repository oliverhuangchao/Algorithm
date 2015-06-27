// find the kth largets number in the array
// use partition
// pay attention the sort order: it should be decesding order

int partition(vector<int> &nums,int start,int end){
    int pivot = nums[start];
    while(start<end){
        while(start<end && nums[end] <= pivot)
            end --;
        nums[start] = nums[end];
        while(start<end && nums[start] >= pivot)
            start ++;
        nums[end] = nums[start];
    }
    nums[start] = pivot;
    return start;
}

int getK(vector<int> &nums,int start,int end,int k){
    int res = partition(nums,start,end);
    if(res == k) return nums[res];
    else{
        if(res>k)
            return getK(nums,start,res-1,k);
        else
            return getK(nums,res+1,end,k);
    }
}
int kthLargestElement(int k, vector<int> nums) {
    // write your code here
    // heap can do it in O(nlogn) time.
    // O(n) solution
    return getK(nums,0,nums.size()-1,k-1);
}
