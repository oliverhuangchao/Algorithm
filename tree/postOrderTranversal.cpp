//classical post order tranversal
void dfs(TreeNode* root, vector<int>& result){
    if(root == NULL) return;
    if(root->left != NULL) dfs(root->left, result);
    if(root->right != NULL) dfs(root->right, result);
    result.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    dfs(root,result);
    return result;
}