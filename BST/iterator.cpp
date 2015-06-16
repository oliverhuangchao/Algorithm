class Solution {
public:
    //@param root: The root of binary tree.
    stack<TreeNode*> s;
    TreeNode* tmp;
    Solution(TreeNode *root) {
        // write your code here
        tmp = root;
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !s.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* res = NULL;
        if(hasNext()){
            res = s.top();
            s.pop();
        }
        else
            return NULL;
        tmp = res->right;
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
        return res;
    }
};