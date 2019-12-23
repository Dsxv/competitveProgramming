#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5005 , M = 5005 ;
int dp[N][M] ;

int solve(int* b , int* g , int& n , int m , int i = 0 , int j = 0 ){
	if(j == m && i != n) return INT_MAX ;
	if(i == n) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	return dp[i][j] = min(solve(b,g,n,m,i+1,j+1) + abs(b[i]-g[j]) ,
					solve(b,g,n,m,i,j+1)) ;
}

int32_t main(){
	int n , m ; // n = boys , m = girls
	cin >> n >> m ;
	int b[n] , g[m] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	for(int j = 0 ; j < m ; j++) cin >> g[j] ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++) dp[i][j] = -1 ;
	}

	sort(b,b+n) ; sort(g,g+m) ;
	cout << solve(b,g,n,m) ;
	return 0 ;
}

