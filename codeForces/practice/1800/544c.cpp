#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 505 ;
int dp[2][N][N] ;
int a[N] ;
int n , m , b , mod ;

// i , j , k => current person , current line , current errors 

int solve(int i = 0 , int j = 0 , int k = 0){
	if(k > b || j > m){
		return 0 ;
	}
	if(i == n){
		return (k <= b && j == m) ;	
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	return dp[i][j][k] = (solve(i,j+1,k+a[i]) + solve(i+1,j,k)) % mod ;
}

int32_t main(){
	cin >> n >> m >> b >> mod ;
	for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
	//cout << solve() ;
	dp[0][0][0] = 1 ;
	// except this dp[0][i][j] will be 0 cuz you can't write anything without people
	for(int it = 1 ; it <= n ; it++){
		int i = it&1 ;
		for(int j = 0 ; j <= m ; j++){
			for(int k = 0 ; k <= b ; k++){
				dp[i][j][k] = dp[i^1][j][k] ;
				if(j >= 1 && k >= a[it]){
					dp[i][j][k] += dp[i][j-1][k-a[it]];
				}
				if(dp[i][j][k] >= mod) dp[i][j][k] -= mod ;
			}
		}
	}
	// dp[n&1][m][0] to dp[n&1][m][b]
	int ans = 0 ;
	for(int k = 0 ; k <= b ; k++){
		ans += dp[n&1][m][k] ;
		if(ans >= mod) ans -= mod ;
	}
	cout << ans ;
	return 0 ;
}

