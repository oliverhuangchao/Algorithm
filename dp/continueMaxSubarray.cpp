/*
    given an array, return the max sum of the subarray in this array
*/
vector<int> continuousSubarraySum(vector<int>& A) {
    // Write your code here
    // O(n) solution
    int size = A.size();
    int p[size];
    int z[size];
    fill_n(&p[0],size,0);
    fill_n(&z[0],size,0);
    p[0] = A[0];
    z[0] = 0;
    //print(p,size);
    //print(z,size);
    for(int i=1;i<size;i++){
        if(p[i-1]+A[i] >= A[i]){
            p[i] = p[i-1] + A[i];
            z[i] = z[i-1];
        }
        else{
            p[i] = A[i];
            z[i] = i;
        }
    }
    int start = 0;
    int end = 0;
    int maxvalue = p[0];
    for(int i=1;i<size;i++){
        if(p[i] > maxvalue){
            start = z[i];
            end = i;
            maxvalue = p[i];
        }
    }
    vector<int> res;
    res.push_back(A[start]);
    res.push_back(A[end]);
    return res;
}