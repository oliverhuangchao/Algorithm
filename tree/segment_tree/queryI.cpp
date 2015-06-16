int query(SegmentTreeNode *root, int start, int end) {
    // write your code here
    // 类似于一个binary search的过程
    if(root->start == start && root->end == end) return root->max;
    
    int mid = (root->start  + root->end) / 2;
    
    if(start > mid) //在树的右边
        return query(root->right,start,end);
    else if(end <= mid) // 树的右边
        // pay attention  end <= mid
        return query(root->left,start,end);
    else// 如果横跨中间的话，求最大值
        return max(query(root->right,mid+1,end),query(root->left,start,mid));
        
}