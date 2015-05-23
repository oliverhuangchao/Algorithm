//find the kth largest element in an unsorted array
//use a min heap to perserve all the elements in this array
//the heap size is k
//each time input a number and compare to the heap.top
//if the current number is bigger than delete the top value and push this number into the heap and update the heap
int findKthLargest(vector<int>& nums, int k){
    //if(nums.empty()) return 
    priority_queue<int,vector<int>,greater<int>> q;//最小堆，k个数里面最小的值凡在最顶端
    int count = 0;
    int i=0;
    while(i<k && i<nums.size())
        q.push(nums[i++]);
    while(i<nums.size()){
        if(q.top()<nums[i]){
            q.pop();
            q.push(nums[i]);
        }
        i++;
    }
    return q.top();
}