//decare tree construction
// it has many application using find the kth element
//
TreeNode* maxTree(vector<int> A) {
    if(A.empty()) return NULL;
    stack<TreeNode*> mystack;
    TreeNode* first = new TreeNode(A[0]);
    mystack.push(first);
    for(int i=1;i<A.size();i++){
        TreeNode* newnode = new TreeNode(A[i]);
        if(A[i] > mystack.top()->val){
            TreeNode* n1 = mystack.top();
            mystack.pop();
            while(!mystack.empty() && A[i]>mystack.top()->val){
                mystack.top()->right = n1;
                n1 = mystack.top();
                mystack.pop();
            }
            newnode->left = n1;
        }
        mystack.push(newnode);
    }
    TreeNode* tmp = mystack.top();
    mystack.pop();
    while(!mystack.empty()){
        mystack.top()->right = tmp;
        tmp = mystack.top();
        mystack.pop();
    }
    return tmp;
}