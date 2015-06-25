// this should be a greedy solution, get the number from the biggest
/*
From a given integer array values, find if a Total value is possible or not? The numbers in the array can be used more than once. 
example 
int[] points = {3, 7}; 
isScorePossible(points, 10) => true 
isScorePossible(points, 9) => trues
*/ 
bool dfs(const vector<int> &nums,const int target, int current,int pos, vector<int> &q){
	//if(pos == nums.size()) return false;
	if(current> target || pos == nums.size()) return false;
	if(current == target){
		return true;
	}
	int i=pos;
	while(i<nums.size()){
		q.push_back(nums[i]);
		if(dfs(nums,target,current+nums[i],i,q) == false){
			q.pop_back();
			if(i == nums.size()){
				q.pop_back();
				i = pos;
			}
		}
		else
			return true;
		i++;
	}

}
int main(){
	int a[] = {3,7};
	int size = sizeof(a)/sizeof(a[0]);
	vector<int> nums = getVector(a,size);
	int value;
	cin>>value;


	/* dfs solution */
	/*sort(nums.begin(),nums.end(),greater<int>());
	print(nums);
	int current = 0;
	vector<int> q;
	cout<<dfs(nums,value,current,0,q);
	cout<<endl;*/

	/* dp solution */

	bool x[value+1];
	fill_n(&x[0],value+1,false);
	x[0] = true;
	for(int i=0;i<size;i++){
		for(int j=nums[i];j<=value;j++)
			x[j] = x[j-nums[i]] || x[j]; 
	}
	print(x[value]);
	return 0;	

}