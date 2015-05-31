//we can move from the pricess to the knight
//similar to the gas station problem
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    if(rows == 0)
        return 0;
    int cols = dungeon[0].size();
   /* for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            dungeon[i][j] *= -1;
    }*/
    vector<vector<int>> grid(rows,vector<int>(cols,0));
    grid[rows-1][cols-1] = 1 + dungeon[rows-1][cols-1];
    if(grid[rows-1][cols-1] < 1)
       grid[rows-1][cols-1] = 1;
    for(int i=rows-2;i>=0;i--){
        grid[i][cols-1] = grid[i+1][cols-1] + dungeon[i][cols-1];
        if(grid[i][cols-1] < 1)
            grid[i][cols-1] = 1;
    }
    for(int i=cols-2;i>=0;i--){
        grid[rows-1][i] = grid[rows-1][i+1] + dungeon[rows-1][i];
        if(grid[rows-1][i]<1)
            grid[rows-1][i] = 1;
    }
    for(int i= rows-2;i>=0;i--){
        for(int j = cols-2;j>=0;j--){
            /*if(grid[i+1][j] != INT_MAX && grid[i][j+1] != INT_MAX)
                grid[i][j] = min(grid[i+1][j], grid[i][j+1]);
            else{
                if(grid[i+1][j] == INT_MAX && grid[i][j+1] == INT_MAX)
                    grid[i][j] == 1;
                else{
                    if(grid[i+1][j] == INT_MAX) grid[i][j] = grid[i][j+1];
                    else grid[i][j] = grid[i+1][j];
                }
            }*/
            int right = grid[i][j+1] + dungeon[i][j] > 0 ? grid[i][j+1] + dungeon[i][j] : 1;
            int down  = grid[i+1][j] + dungeon[i][j] > 0 ? grid[i+1][j] + dungeon[i][j] : 1;
            grid[i][j] = min(right,down); 
        }
    }
    return grid[0][0];// == INT_MAX? 1 : grid[0][0];
 }