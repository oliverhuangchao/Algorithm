// build a segment tree
// all the leaves are single integer segment
SegmentTreeNode * build(int start, int end) {
    // write your code here
    if(start > end) return NULL;
    if(start == end){
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        return root;
    }
    else{
        int mid = (start+end)/2;
        SegmentTreeNode *root = new SegmentTreeNode(start,end);
        root->left = build(start,mid);
        root->right = build(mid+1,end);
        return root;
    }
}