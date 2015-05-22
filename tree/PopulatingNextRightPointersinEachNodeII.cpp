// tree level order tranversal
// BFS mehod
void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    queue<TreeLinkNode*> parent;
    queue<TreeLinkNode*> children;
    TreeLinkNode* tmp;
    parent.push(root);
    while(!parent.empty()){
        tmp = parent.front();
        parent.pop();
        if(!parent.empty())
            tmp->next = parent.front();
        else
            tmp->next = NULL;
            
        if(tmp->left != NULL){
            children.push(tmp->left);
        }
        if(tmp->right != NULL){
            children.push(tmp->right);
        }
        if(parent.empty()){
            while(!children.empty()){
                parent.push(children.front());
                children.pop();
            }
        }
    }
}