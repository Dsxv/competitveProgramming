#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ;
int dp[N][N] ;
int n , m ;

int solve(vector<pair<int,int>>& v , int i = 0 , int j = 0 ){
	if(i == n || j == m) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(v[i].second + j <= m) {
		return dp[i][j] = max( solve(v,i,j+v[i].second) + v[i].first  ,
								solve(v,i+1,j) ) ;
	} else {
		return dp[i][j] = solve(v,i+1,j) ;
	}
}

int32_t main(){
	cin >> n >> m ;
	vector<pair<int,int>> v(n) ;
	for(int i = 0 ; i < n ; i++) cin >> v[i].second ;
	for(int i = 0 ; i < n ; i++) cin >> v[i].first ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++) dp[i][j] = -1 ;
	}
	cout << solve(v) ;
	return 0 ;
}

