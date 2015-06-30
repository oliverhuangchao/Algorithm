#include "basic.h"
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    // write your code here
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<TreeNode*> parent;
    queue<TreeNode*> children;
    parent.push(root);
    TreeNode* tmp;
    vector<int> path;
    path.push_back(root->val);
    res.push_back(path);
    path.clear();
    bool flag = false;
    while(!parent.empty()){
        tmp = parent.front();
        parent.pop();
        if(tmp->left)
            children.push(tmp->left);
        if(tmp->right)
            children.push(tmp->right);
        if(parent.empty()){
            while(!children.empty()){
                parent.push(children.front());
                path.push_back(children.front()->val);
                children.pop();
            }
            if(!flag){
                reverse(path.begin(),path.end());
            }
            if(!parent.empty())
                res.push_back(path);
            path.clear();
            flag = !flag;
        }
    }
    return res;
}

int main(){
	int x[] = {-1,0, 1, 2, -1, -4};
	int len = sizeof(x)/sizeof(x[0]);
	vector<int> nums = getVector(x,len);
	print(threeSum(nums));
}