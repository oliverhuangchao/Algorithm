typedef vector<int> vi;
void dfs(vi &path, vector<vi> &result, int current, int step, const int& k, int sum){
    if(step == k && sum == 0){
        result.push_back(path);
        return;
    }
    for(int i=current; i<10 && sum > 0; i++){
        path.push_back(i);
        dfs(path,result,i+1,step+1,k,sum-i);
        path.pop_back(i);
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vi> res;
    vi path;
    dfs(path,res,0,0,k,n);
    return res;
}