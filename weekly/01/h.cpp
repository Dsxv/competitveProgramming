#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 5 ;
const int mod = 998244353 ;
int dp[N][N] ;
int n , m , k ;

int solve(int i  = 0  , int j = 0){
	if(i == n) return j == k ;
	if(j > k) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(i == 0){
		dp[i][j] = (m*solve(i+1,j)) % mod ;
	} else {
		dp[i][j] = ((m-1)*solve(i+1,j+1)) % mod ;
		dp[i][j] = (dp[i][j] + solve(i+1,j)) % mod ;
	}
	dp[i][j] %= mod ;
	return dp[i][j] ;
}
int32_t main(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++) dp[i][j] = -1 ;
	}
	cin >> n >> m >> k ;
	cout << solve() ;
	return 0 ;
}

