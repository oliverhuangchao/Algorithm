// this should be a greedy solution, get the number from the biggest
/*
From a given integer array values, find if a Total value is possible or not? The numbers in the array can be used more than once. 
example 
int[] points = {3, 7}; 
isScorePossible(points, 10) => true 
isScorePossible(points, 9) => true

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
	int x[] = {3,7};
	int size = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,size);
	int value;
	cin>>value;
	/*for(int i=0;i<size;i++){
		int tmp;
		cin>>tmp;
		nums.push_back(tmp);
	}
	print(nums);*/
	sort(nums.begin(),nums.end(),greater<int>());
	print(nums);
	int current = 0;
	vector<int> q;
	cout<<dfs(nums,value,current,0,q);
	cout<<endl;
}