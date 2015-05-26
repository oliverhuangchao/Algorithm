vector<int> twoSum(vector<int> &numbers, int target) {
    std::unordered_map<int,int> x;
    std::vector<int> result;
    int size = numbers.size();
    
    for(int i=0;i<numbers.size();i++){
        if(x.find(numbers[i]) == x.end()){
            x[numbers[i]] = i;
        }            
        else{
            if(numbers[i]*2 == target){
                result.push_back(x[numbers[i]]+1);
                result.push_back(i+1);
                cout<<"find it same"<<endl;
                return result;
            }
        }
    }
    
    for(int i=0;i<numbers.size();i++){
        if(x.find(target-numbers[i]) != x.end() && i != x[target - numbers[i]] ){
            cout<<"find different"<<endl;
            result.push_back(x[numbers[i]]+1);
            result.push_back(x[target - numbers[i]]+1);
            return result;
        }
    }
    return result;
}