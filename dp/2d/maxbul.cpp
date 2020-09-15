#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e3 + 10 , INF = -1e17;
int dp[N][N] ;
int a[N] , b[N] ;
int n , x,  y;
int solve(int i = 0 , int j = 0){
	if(i == n){
		return 0 ;
	}
	if(j > x || (i-j) > y){
		return INT_MIN ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	return dp[i][j] = max(solve(i+1,j+1) + a[i] , solve(i+1,j) + b[i]) ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> x >> y ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	cout << solve() ;
	return 0 ;
}

