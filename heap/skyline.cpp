typedef vector<int> vi;
class mycomp{
public:
	bool operator()(const vector<int> &num1,const vector<int> &num2){
		return num1.back() < num2.back();
	}
};
vector<pair<int,int>> getSkyline(vector<vector<int>> buildings){
	priority_queue<vi,vector<vi>,mycomp> heap;
	/*int x[] = {1,2,3};
	int y[] = {2,3,4};
	vector<int> num1 = getVector(x,3);
	vector<int> num2 = getVector(y,3);
	heap.push(num1);
	heap.push(num2);
	print(heap.top());*/
	vector<pair<int,int>> res;
	vector<int> tmp;
	vector<int> top;
	tmp = buildings[0];
	heap.push(tmp);
	res.push_back(make_pair(tmp[0],tmp[2]));
	int i = 1;
	while(i<buildings.size()){
		tmp = buildings[i];
		top = heap.top();
		if(tmp[0] > top[0]){
			res.push(make_pair(top[1],0));
			heap.clear();
			continue;
		}
		if(tmp[2] > top[2]){
			heap.push(tmp);
			res.push(make_pair(tmp[0],tmp[2]));
		}
		else{
			if(tmp[1] > top[1]){
				res.push_back(make_pair(top[1],tmp[2]));
				heap.push(tmp);
				heap.pop();
			}
		}
		i++;
	}
	return res;
}