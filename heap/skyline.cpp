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

int main(int argc, char *argv[]){
	vector<vector<int>> buildings;
	int x[] = {0,2147483647,2147483647};
	//int x[] = {2, 9,10 3, 7, 15, 5, 12, 12, 15, 20, 10, 19, 24, 8}; 
	//int x[] = {0,2,3,2,5,3};
	int len = sizeof(x)/sizeof(x[0]);
	//vector<int> num = getVector(x,len);
	int count = 0;
	int i=0;
	vector<int> each;
	while(i<len){
		if(count == 3){
			buildings.push_back(each);
			count = 0;
			each.clear();
		}
		else{
			each.push_back(x[i++]);
			count ++;
		}
	}
	buildings.push_back(each);
	//print(buildings);

	cout<<endl;
	vector<pair<int,int>> res = getSkyline(buildings);
	print(res);
}