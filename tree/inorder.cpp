//use stack to deal with it
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> nums;
    if(!root) return nums;
    stack<TreeNode *> z;
    TreeNode *tmp = NULL;//key point to tranversal
    while(root || !z.empty()){
        while(root){
            z.push(root);
            root = root->left;
        }
        tmp = z.top();
        nums.push_back(tmp->val);//放在这里就是终序遍历
        z.pop();
        root = tmp->right; // 关键的一个步骤，使得树的方向向右边的方向走
    }
    return nums;
}
//use recursive function
//
void dfs(TreeNode* root,vector<int>& z){
    if(root == NULL) return;
    dfs(root->left,z);
    z.push_back(root->val);
    dfs(root->right,z);
    return;
}
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> z;
    inorder(root,z);
    return z;
}

