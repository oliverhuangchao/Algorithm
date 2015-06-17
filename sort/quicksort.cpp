// quick sort procedure
// two pointers solution 
// pivot could be the mid element
int partition(vector<int> &nums,int start,int end){
    int pivot = nums[start];
    
    while(start < end){
        while(start < end && nums[end] >= pivot){
            end --;
        }
        nums[start] = nums[end];
        while(start<end && nums[start] <= pivot){
            start ++;
        }
        nums[end] = nums[start];
    }
    nums[start] = pivot;
    return start;
}
void qsort(vector<int> &nums,int start,int end){
    if(start >= end) return;
    int mid = partition(nums,start,end);
    qsort(nums,start,mid-1);
    qsort(nums,mid+1,end);
    return;
}