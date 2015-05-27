typedef vector<int> vi;
class mycomp{
public:
bool operator()(const vector<int> &num1,const vector<int> &num2){
		return num1.back() < num2.back();
	}
};
void heapclear(priority_queue<vi,vector<vi>,mycomp> & heap){
	while(!heap.empty()){
		heap.pop();
	}
	return;
}
vector<pair<int,int>> getSkyline(vector<vector<int>> buildings){
	vector<pair<int,int>> getSkyline(vector<vector<int>> buildings){
	vector<pair<int,int>> res;
	if(buildings.empty()) return res;
	priority_queue<vi,vector<vi>,mycomp> heap;
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
			res.push_back(make_pair(top[1],0));
			heapclear(heap);
			heap.push(tmp);
			res.push_back(make_pair(tmp[0],tmp[2]));
			i++;
			continue;
		}
		if(tmp[2] > top[2]){
			heap.push(tmp);
			res.push_back(make_pair(tmp[0],tmp[2]));
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
	while(!heap.empty()){
		top = heap.top();
		int w = top[1];
		heap.pop();
		if(!heap.empty()){
		//	res.push_back(make_pair(w, 0));
		//else{
			top = heap.top();
			res.push_back(make_pair(w, top[2]));
		}
	}
	return res;
}
}