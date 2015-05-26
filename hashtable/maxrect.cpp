int getLargest(vector<int> height) {
    if(height.size() == 0) return 0;
    if(height.size() == 1) return height[0];
    stack<int> s;
    height.push_back(0);
    int i = 0, j = 0, maxvalue = 0;
    while(i<height.size()){
        if(s.empty() || height[i]>height[s.top()]){
            s.push(i);
            i++;
        }
        else{
            int h = height[s.top()];
            s.pop();
            j = s.empty()?-1:s.top();
            maxvalue = max(maxvalue, h*(i-j-1));
        }
    }
    return maxvalue;
}

int maximalRectangle(vector<vector<char> > &matrix) {
    int rows = matrix.size();
    if(rows == 0) return 0;
    int cols = matrix[0].size();
    vector<int> height(cols,0);
   
    vector<vector<int>> value(rows,vector<int>(cols,0));

    for(int j = 0;j<cols;j++)
        value[0][j] = (int)(matrix[0][j] -48);
    
    int result = getLargest(value[0]);
    
    for(int i = 1;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(matrix[i][j] == '1')
                value[i][j] = value[i-1][j]+1;
            else
                value[i][j] = 0;
        }
        result = max(result,getLargest(value[i]));
    }
    return result;
}