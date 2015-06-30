// whether a bst is a valid bst

int minvalue(TreeNode *root){
    while(root->left){
        root = root->left;
    }
    return root->val;
}

int maxvalue(TreeNode *root){
    while(root->right){
        root = root->right;
    }
    return root->val;
}
 
bool isValidBST(TreeNode *root) {
    // write your code here
    if(root == NULL) return true;
    return isValidBST(root->left) && isValidBST(root->right) && (root->left == NULL || root->val > maxvalue(root->left)) && (root->right == NULL || root->val < minvalue(root->right)); 
 }