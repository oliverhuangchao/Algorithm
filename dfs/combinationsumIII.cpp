typedef vector<int> vi;
void dfs(vi &path, vector<vi> &result, const int& k, int sum){
    if(path.size() == k && sum == 0){
        result.push_back(path);
        return;
    }
    for(int i=path.empty()?1:path.back()+1; i<10 && sum > 0; i++){
        path.push_back(i);
        dfs(path,result,k,sum-i);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vi> res;
    vi path;
    dfs(path,res,k,n);
    return res;
}