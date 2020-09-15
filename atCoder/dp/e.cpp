#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 105 , M = 1e5 + 10 ;
int dp[N][M] ;
const int INF = 1e15 ;
int a[N] , b[N] ;
int n , w ;
int solve(int i , int j){
	if(j <= 0) return 0 ;
	if(i == n) return INF ;
	if(~dp[i][j]) return dp[i][j] ;
	return dp[i][j] = min(solve(i + 1 , j - b[i]) + a[i] , solve(i + 1 , j)) ;
}

int32_t main(){
	cin >> n >> w ;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i] ;
	int ans = 0 ;
	for(int i = 0 ; i < M ; i++){
		if(solve(0,i) <= w) ans = i ;
	}
	cout << ans ;
	return 0 ;
}

