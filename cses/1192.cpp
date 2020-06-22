#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {1,-1,0,0} ;
int yy[4] = {0,0,1,-1} ;
const int N = 1000 ;
char ch[N][N] ;
int visited[N][N] ;
int32_t main(){
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> ch[i][j] ;
		}
	}
	function<void(int,int)> dfs;
	int a[n] = {} ;
	dfs = [&](int x , int y) -> void {
		if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) return ;
		if(ch[x][y] != '.') return ;
		visited[x][y] = 1 ;
		for(int i = 0 ;  i < 4 ; i++){
			dfs(x + xx[i] , y + yy[i]) ;
		}
		return ;
	} ;
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ch[i][j] == '.' && !visited[i][j]) {
				dfs(i,j) ;
				cnt++ ;
			}
		}
	}
	cout << cnt ;
	return 0 ;
}

