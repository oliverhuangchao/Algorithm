// count the total number of nodes in a complete bst
int getHeight(TreeNode* root){
    if(!root) return 0;
    return getHeight(root->left)+1;
}
int findRest(TreeNode* root,int h){
    if(h == 1) return 1;
    if(getHeight(root->right)+1 == h)
        return (int)pow(2,h-2) + findRest(root->right,h-1);
    else
        return findRest(root->left,h-1);
}
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int h = getHeight(root);
    int count = (int)pow(2,h-1)-1;
    return count+findRest(root,h);
}