#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e4 + 10 , M = 1e3 + 10 ;
int dp[N][M][2] ;
int n , m ;

int solve(int* a , int i = 0 , int j = 0 , int k = 0){
	if(j > m) return INT_MIN ;
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(k){
		return dp[i][j][k] = solve(a,i+1,j,0) ;
	} else {
		return	dp[i][j][k] = max(solve(a,i+1,j+a[i],1) + a[i] , solve(a,i+1,j,0)) ;
	}
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> m ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(a) ;
	return 0 ;
}

