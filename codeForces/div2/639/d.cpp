#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 10 ;
char ans[N][N] ;
int visited[N][N] ;

int dx[4] = {0,0,-1,1} ;
int dy[4] = {-1,1,0,0} ;

void dfs(int x , int y , int n ,  int m){
	visited[x][y] = 1 ;
	for(int i = 0 ; i < 4 ; i++){
		int xi = x + dx[i] , yi = y + dy[i] ;
		if(xi >= 0 && xi < n && yi >= 0 && yi < m && !visited[xi][yi] && ans[xi][yi] == 's'){
			dfs(xi , yi , n , m) ;
		}
	}
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	char ch[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) {
			cin >> ch[i][j] ;
			ans[i][j] = '.' ;
		}
	}
	int row[n] = {} , col[m] = {} ;
	for(int i = 0 ; i < n ; i++){
		vector<char> v ; v.push_back(ch[i][0]) ;
		for(int j = 1 ; j < m ; j++){
			if(ch[i][j] != v.back()) v.push_back(ch[i][j]) ;
		}
		row[i] = count(v.begin() , v.end() , '#') ;
	}
	for(int j = 0 ; j < m ; j++){
		vector<int> v ; v.push_back(ch[0][j]) ;
		for(int i = 1 ; i < n ; i++){
			if(ch[i][j] != v.back()) v.push_back(ch[i][j]) ;
		}
		col[j] = count(v.begin() , v.end() , '#') ;
	}
	int okr[n] = {} , okc[m] = {} ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(row[i] == 1 && col[j] == 1 && ch[i][j] == '#'){
				ans[i][j] = 's' ;
				okr[i] = okc[j] = 1 ;
			}
			if(row[i] == 0 && col[j] == 0){
				okr[i] = okc[j] = 1 ;
			}
		}
	}
	if((count(okr , okr + n ,1) + count(okc , okc + m ,1)) != (n + m)){
		cout << -1 ;
		return 0 ;
	}
	int val = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ch[i][j] == '#'){
				if(!visited[i][j]){
					dfs(i , j , n , m) ;
					val++ ;
				}
			}
		}
	}
	cout << val ;
	return 0 ;
}

