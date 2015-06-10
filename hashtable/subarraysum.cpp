 vector<int> subarraySum(vector<int> nums){
    // O(N) solution
    // write your code here
    vector<int> res;
    int len = nums.size();
    int p[len];
    fill_n(&p[0],len,0);
    p[0] = nums[0];
    if(p[0] == 0)
        return res(2,0);
    unordered_map<int,int> hash;
    hash.insert({p[0],0});
    for(int i=1;i<nums.size();i++){
        p[i] = p[i-1] + nums[i];
        if(p[i] == 0) return vector<int>(2,i);
        if(hash.find(p[i]) == hash.end())
            hash.insert({p[i],i});
        else{
            res.push_back(hash[p[i]]+1);
            res.push_back(i);
            return res;
        }
    }
    return res;
}