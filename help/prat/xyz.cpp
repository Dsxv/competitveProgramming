#include <bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<bool>> instack ;
bool found ;
void dfs(vector<vector<char>>& v, int cnt = 0 , int row = 0 , int col = 0){
	if(row < 0 || row >= m || col < 0 || col >= n) return ;
	if(instack[row][col] || cnt < 0) return ;
	if(v[row][col] == '(') cnt++ ;
	else cnt-- ;
	if(row == m - 1 && col == n - 1) {
		found |= cnt == 0 ;
		return ;
	}
	instack[row][col] = 1 ;
	dfs(v , cnt , row + 1 , col) ;
	dfs(v , cnt , row - 1 , col) ;
	dfs(v , cnt , row , col - 1) ; 
	dfs(v , cnt , row , col + 1) ;
	instack[row][col] = 0 ;
}

int main() {
    
    cin>>m>>n;
    vector<vector<char>> vec(m,vector<char>(n,'.'));
	instack = vector<vector<bool>>( m , vector<bool>(n)) ;
    for(int i = 0; i < m ;++i){
        for(int j = 0 ; j < n; ++j){
            cin >> vec[i][j];
        }
    }
	dfs(vec) ;
    cout << found ;
	return 0;
}
