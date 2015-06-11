vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
    // O(n2) solution
    // Write your code here
    int rows = matrix.size();
    int cols = matrix[0].size();
    int p[rows][cols];
    p[0][0] = matrix[0][0];
    for(int i=1;i<rows;i++)
        p[i][0] = p[i-1][0] + matrix[i][0];
    for(int j=1;j<cols;j++)
        p[0][j] = p[0][j-1] + matrix[0][j];
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++)
            p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + matrix[i][j];
    }
    vector<vector<int>> res;
    vector<int> p1;
    vector<int> p2;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(p[i][j] == 0){
                p1.push_back(0);
                p1.push_back(0);
                p2.push_back(i);
                p2.push_back(j);
                res.push_back(p1);
                res.push_back(p2);
                return res;
            }
            for(int a=i;a<rows;a++){
                for(int b=j;b<cols;b++){
                    if(p[i][j]+p[a][b] == p[i][b] + p[a][j]){
                        p1.push_back(i+1);
                        p1.push_back(j+1);
                        p2.push_back(a);
                        p2.push_back(b);
                        res.push_back(p1);
                        res.push_back(p2);
                        return res;
                    }
                }
            }
        }
    }
    return res;
}