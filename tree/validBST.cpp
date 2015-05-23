//detect a BT is a binary search tree
int findmin(TreeNode *root){
    if(root->left)
        return findmin(root->left);
    else
        return root->val;
}

int findmax(TreeNode *root){
    if(root->right)
        return findmax(root->right);
    else
        return root->val;
}
//four conditions 
//1.2. recursively run the bst to check its validation
//3.4. root value should obey the rules
bool isValidBST(TreeNode *root) {
    if(!root) return true;
    return isValidBST(root->left) && 
           isValidBST(root->right) && 
           (!root->left || (findmax(root->left) < root->val)) && 
           (!root->right || (findmin(root->right) > root->val)); 
}