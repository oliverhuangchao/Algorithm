void inorder(TreeNode *root, vector<int>& result){
    if(!root) return;
    inorder(root->left,result);
    result.push_back(root->val);
    inorder(root->right,result);
}

TreeNode* findNode(TreeNode *root, int x){
    if(!root) 
        return NULL;
    TreeNode* a;
    if(root->val == x) 
        return root;
    a = findNode(root->left,x);
    if(a)
        return a;
    else
        return findNode(root->right,x);
}
void recoverTree(TreeNode *root) {
    vector<int> r;
    inorder(root,r);
    int big,small;
    int i;
    for(i=0;i<r.size()-1;i++){
        if(r[i]>r[i+1]){
            big = r[i];
            break;
        }
    }
    for(i = r.size()-1;i>0;i--){
        if(r[i]<r[i-1]){
            small = r[i];
            break;
        }
    }
    
    TreeNode *first, *second;
    first = findNode(root,big);
    second = findNode(root,small);
    
    first->val = small;
    second->val = big;
    
    return;
}