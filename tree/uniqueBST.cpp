vector<TreeNode*> dp(int start,int end){
    vector<TreeNode*> tmp;
    if(start == end){
        TreeNode* root = new TreeNode(start);
        root->left = NULL;
        root->right = NULL;
        //result.push_back(root);
        tmp.push_back(root);
        return tmp;
    }
    vector<TreeNode*> l;
    vector<TreeNode*> r;
    for(int i=start;i<=end;i++){
        if(i == start) 
            l.push_back(NULL);
        else
            l = dp(start,i-1);
        
        if(i == end)
            r.push_back(NULL);
        else
            r = dp(i+1,end);
        
        for(int m=0;m<l.size();m++){
            for(int n=0;n<r.size();n++){
                TreeNode* root = new TreeNode(i);
                root->left = l[m];
                root->right = r[n];
                tmp.push_back(root);
            }
        }
        r.clear();
        l.clear();
    }
    return tmp;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode*> result;
    if(n == 0){
        result.push_back(NULL);
        return result;
    }
    result = dp(1,n);
    //sort(result.begin(),result.end());
    //result.erase(unique(result.begin(),result.end(),myfunction),result.end());
    return result;
}