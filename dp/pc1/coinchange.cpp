#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 ;

int dp[N][N] ;

int solve(int* a , int n , int m , int i = 0 , int j = 0 ){
	if(i == n) return 1 ;
	if(i > n ) return 0 ;
	if(j == m) return 0 ;
	
	if(dp[i][j] != -1) return dp[i][j] ;
	return dp[i][j] = solve(a,n,m,i+a[j],j) + solve(a,n,m,i,j+1) ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++) dp[i][j] = -1 ;
	}
	int a[m] ;
	for(int i = 0 ; i < m ; i++) cin >> a[i] ;
	cout << solve(a,n,m) ;
	return 0 ;
}

