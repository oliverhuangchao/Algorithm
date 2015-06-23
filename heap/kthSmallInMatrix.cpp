// given a sorted matrix in every row and column
// find the kth smallest value in this matrix
// heap solution
//自定义一个类存储value和矩阵的位置
class node{
public:
    int value;
    int row;
    int col;
    node(int a,int x,int y){
        value = a;
        row = x;
        col = y;
    }
};
// 自定义比较关系，放入priority_queue中
class mycomp{
public:
    bool operator()(node &x, node &y){
        return x.value>y.value;
    }
};


class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
     
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<node,vector<node>,mycomp> z;
        for(int i=0;i<cols;i++){
            node tmpnode(matrix[0][i], 0, i);//  注意下标
            z.push(tmpnode);
        }
        int res;
        for(int i=0;i<k;i++){
            node topnode = z.top();
            res = topnode.value;
            if(topnode.row < rows-1){
                node newnode(matrix[topnode.row+1][topnode.col],topnode.row+1,topnode.col);
                z.push(newnode);
            }
            z.pop();
        }
        return res;
    }
};
