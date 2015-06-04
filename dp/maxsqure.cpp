//classical dp problem
// return the max square contains all 1's
// each f[i][j] record the area which right-buttom corner is matrix[i][j]
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxval = 0;
    int f[rows+1][cols+1];
    fill_n(&f[0][0],(rows+1)*(cols+1),0);
    //vector<vector<int>> f(rows+1,vector<int>(cols+1,0));
    //f[0][0] = 1;
    for(int i=1;i<rows+1;i++){
        for(int j=1;j<cols+1;j++){
            if(matrix[i-1][j-1] == '1'){
                if(f[i-1][j]>=f[i-1][j-1] && f[i][j-1]>=f[i-1][j-1])
                    f[i][j] = (int)pow(sqrt(f[i-1][j-1])+1,2);
                else{
                    int up = sqrt(f[i-1][j]);
                    int left = sqrt(f[i][j-1]);
                    int final = min(up,left);
                    f[i][j] = (int)pow(final+1,2);
                }
                maxval = max(maxval,f[i][j]);
            }
        }
    }
    return maxval;
}