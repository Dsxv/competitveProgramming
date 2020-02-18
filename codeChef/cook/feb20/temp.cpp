#include <bits/stdc++.h>
using namespace std ;

#define int long long

class Solution {
public:
    int n , m ;
    int dfs(int i , int j , set<int>* row , set<int>* col,vector<vector<int>>& grid){
       if(row[i].count(j)) row[i].erase(j) ;
       if(col[j].count(i)) col[j].erase(i) ;

        int ans = 0 ;
        if(!grid[i][j]) return 0 ;
        grid[i][j] = 0 ;
        if(row[i].size()){
            for(auto x : row[i]){
                ans += dfs(i,x,row,col,grid) ;
            }
        }
        if(col[j].size()){
            for(auto x : col[j]){
                ans += dfs(x,j,row,col,grid) ;
            }
        }
        return ans+1 ;
    }
    
    int countServers(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size() ;
        set<int> row[n] , col[m] ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    row[i].insert(j) ;
                    col[j].insert(i) ;
                }
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    int count = dfs(i,j,row,col,grid) ;
                    if(count > 1){
                        ans += count ;
                    }
                }
            }
        }
        return ans ;
    }
};

int32_t main(){
	Solution s ;
	int n , m ; cin >> n >> m ;
	vector<vector<int>> v(n,vector<int>(m,0)) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> v[i][j] ;
		}
	}
	cout << s.countServers(v) << endl;
	return 0 ;
}

