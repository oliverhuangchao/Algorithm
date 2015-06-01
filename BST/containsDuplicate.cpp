bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(k==0 || nums.size() < 2) return false;
    set<int> bst;
    unordered_map<int,int> hash;
    int i=0;
    while(i<nums.size()){
        if(i>k){ 
            bst.erase(nums[i-k]);
            hash.erase(nums[i-k]);
        }
        if(hash.count(nums[i]) == 0){
            bst.insert(nums[i]);
            hash.insert({nums[i],i});
        }
        else{
            if(i-hash[nums[i]]<=k && t>=0) 
                return true;
            i++;
            continue;
        }
        auto it = bst.find(nums[i]);
        if(it != bst.begin()){
            it--;
            int before = abs(nums[i] - *it);
            if(before>=0 && before<=t)
                return true;
            it++;
        }

        if(++it != bst.end()){
            //it++;
            int after = abs(*it - nums[i]);
            if(after>=0 && after<=t)
                return true;
        }
        i++;
    }
    return false;
}

// more easy solution
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    map<long long,int> M;
    int l=0;
    for (int r=0;r<nums.size();r++) {
        if (r-l>k)
            M.erase(nums[l++]);
        auto it=M.lower_bound(nums[r]-t);//这一步使用的很巧妙
        //compare first, then insert this element
        if (it!=M.end() && abs(it->first-nums[r])<=t)
            return true;
        M[nums[r]]=r;
    }
    return false;
}