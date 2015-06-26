#include "basic.h"
//find equilibrium index 

int findEquilibrium(vector<int> &nums){
	int size = nums.size();
	int left[size];
	int right[size];
	fill_n(&left[0],size,0);
	fill_n(&right[0],size,0);
	left[0] = nums[0];
	right[size-1] = nums[size-1];
	for(int i=1;i<size;i++){
		left[i] = left[i-1] + nums[i];
	}
	
	for(int i=size-2;i>=0;i--){
		right[i] =right[i+1] + nums[i];
	}
	print(left,size);
	print(right,size);
	for(int i=0;i<size;i++){
		if(left[i] - right[i] == 0)
			return i;
	}
	
	return -1;
}



int main(int argc,char* args[]){
	int x[] = {-7, 1, 5, 2, -4, 3, 0};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);
	print(nums);
	print(findEquilibrium(nums));
	return 0;
} 