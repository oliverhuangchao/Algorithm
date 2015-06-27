#include "basic.h"
//find equilibrium index 

vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
   // write your code here
    unordered_map<int, int> map;
    unordered_map<int,DirectedGraphNode*> store;
    
    
    //构建入度值的 hash map
    
    for(DirectedGraphNode* each : graph){
        map.insert({each->label,0});
        store.insert({each->label,each});
    }
    
    for(DirectedGraphNode* each : graph){
        for(auto son: each->neighbors){
            //if(map.find(son) != map.end())
                ++map[son->label];
        }
    }
    //print(map);
    vector<DirectedGraphNode*> res;
    DirectedGraphNode* tmp = NULL;
    queue<int> q;
    
    for(auto it = map.begin(); it != map.end(); it++){
        if(it->second == 0){
            q.push(it->first);
            it->second = -1;
        }
    }

    //print(q);


  //  auto it = map.()


//    print(map);
    //if(q.empty()) return res;
    while(!q.empty()){
        tmp = store[q.front()];
        q.pop();
        res.push_back(tmp);
        for(DirectedGraphNode* son:tmp->neighbors)
            --map[son->label];
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second == 0){
                q.push(it->first);
                //map.erase(each.first);
                it->second = -1;
            }
        }
    }
    //print(res.size());
    return res;       
}

int main(int argc,char* args[]){
	vector<DirectedGraphNode*> graph;
	DirectedGraphNode *x_0 = new DirectedGraphNode(0);
	DirectedGraphNode *x_1 = new DirectedGraphNode(1);
	DirectedGraphNode *x_2 = new DirectedGraphNode(2);
	DirectedGraphNode *x_3 = new DirectedGraphNode(3);
	DirectedGraphNode *x_4 = new DirectedGraphNode(4);
	DirectedGraphNode *x_5 = new DirectedGraphNode(5);

	x_0->neighbors.push_back(x_1);
	x_0->neighbors.push_back(x_2);
	x_0->neighbors.push_back(x_3);

	x_1->neighbors.push_back(x_4);

	x_2->neighbors.push_back(x_4);
	x_2->neighbors.push_back(x_5);

	x_3->neighbors.push_back(x_4);
	x_3->neighbors.push_back(x_5);
	

	graph.push_back(x_0);
	graph.push_back(x_1);
	graph.push_back(x_2);
	graph.push_back(x_3);
	graph.push_back(x_4);
	graph.push_back(x_5);

	///print(graph);
	//vector<DirectedGraphNode*> res = topSort(graph);
	//print(res.back()->label);

	unordered_map<int,int> x;
	x.insert({1,0});
	x.insert({2,2});
	x.insert({3,0});

	for(auto it =x.begin();it != x.end();it++){
		//print(it->first);
		if(it->second == 0)
			x.erase(it--);	
	}
	print(x);

} 