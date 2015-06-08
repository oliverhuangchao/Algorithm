#include "basic.h"
inline vector<string> transform(const vector<int>& path, int n){
    string tmp(n*n, '.');
	//print(path);
    for(auto each:path)
        tmp[each] = 'Q';
    vector<string> result;
    int size = tmp.size();
    int count = 0;
    for(int i=0;i<size;i++){
        if(count == n){
            result.push_back(tmp.substr(i-n,n));
            count = 0;
			//cout<<result.back()<<endl;
		}
        count++;
    }
	result.push_back(tmp.substr(size-n,n));
	//cout<<endl;
    return result;
}
void dfs(vector<int>& path, vector<vector<string>> &result, int step,int n, unordered_map<int,bool>& m_rows, unordered_map<int,bool>& m_cols, unordered_map<int,bool> &m_diag, unordered_map<int,bool> &m_diag_2,int current){
    if(step == n){
        result.push_back(transform(path,n));
		print(path);
        return;
    }
    
    for(int i=current;i<n*n;i++){
        if(m_rows[i/n] && m_cols[i%n] && m_diag[(i/n-i%n)] && m_diag_2[i/n+i%n]){
			path.push_back(i);
			m_rows[i / n] = false; 
			m_cols[i % n] = false; 
			m_diag[(i/n-i%n)] = false;
			m_diag_2[(i/n+i%n)] = false;

            dfs(path,result,step+1,n,m_rows,m_cols,m_diag,m_diag_2,i);
			path.pop_back();
			m_rows[i / n] = true; 
			m_cols[i % n] = true; 
			m_diag[(i/n-i%n)] = true;
			m_diag_2[(i/n+i%n)] = true;
        }
    }
    return;
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string>> result;
    vector<int> path;
    unordered_map<int,bool> m_rows;
    for(int i=0;i<n;i++)
        m_rows.insert({i,true});
    unordered_map<int,bool> m_cols = m_rows;  
	unordered_map<int,bool> m_diag;
	for(int i=-n+1;i<n;i++)
        m_diag.insert({i,true});
	unordered_map<int,bool> m_diag_2;
	for(int i=0;i<2*n-1;i++)
        m_diag_2.insert({i,true});
    dfs(path,result,0,n,m_rows,m_cols,m_diag,m_diag_2,0);
    return result;
}

int main(int argc,char *argv[]){
	int n = atoi(argv[1]);
	vector<vector<string>> result = solveNQueens(n);
	for(auto each: result){
		for(auto sim: each){
			cout<<sim<<endl;
		}
		cout<<endl;
	}

}
