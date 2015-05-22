//search for each node's left and right
// like another question "max sum subarray", similar way
int dfs(TreeNode *root, int &maxvalue){
    if(!root) return 0;
    int l = dfs(root->left,maxvalue);
    int r = dfs(root->right,maxvalue);
    if(l<0) l = 0;// l和r如果小于0，就不予考虑了，直接按照0处理
    if(r<0) r = 0;
    maxvalue = max(maxvalue, l+r+root->val);// 随时更新最大值
    return root->val += max(l,r);// 只记住最大的路径，以及到这个为截止的最大路径是怎么来的，这个值反之在顶点处
}
int maxPathSum(TreeNode *root) {
    int result = INT_MIN;
    dfs(root,result);
    return result;
}