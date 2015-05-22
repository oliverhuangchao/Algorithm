//conver a sorted arry to binary search tree
//Recursive method
//find the median value and make as the root
//do the left branch using the first part
//do the right branch using the second part
TreeNode *sortedArrayToBST(vector<int> &num) {
    int size = num.size();
    if(size == 1){
        TreeNode* root = new TreeNode(num[0]);
        return root;
    }
    if(size == 0)
        return NULL;
    if(size == 2){
        TreeNode *root = new TreeNode(num[0]);
        if(num[1]>num[0]) root->right = new TreeNode(num[1]);
        else root->left = new TreeNode(num[1]);
        return root;
    }
    TreeNode* root = new TreeNode(num[size/2]);
    vector<int> left(num.begin(),num.begin()+size/2);
    vector<int> right(num.begin()+size/2+1,num.end());
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}