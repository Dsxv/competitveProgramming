#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 2 ;
int dp[N][N][11][2] ;
int n , m , K;
string s , t ;

int solve(int i = 0 , int j = 0 , int  k = 0 , bool ok = false){
	if(i == n or j == m){
		return (k == K? 0 : INT_MIN);
	}
	if(dp[i][j][k][ok] != -1) return dp[i][j][k][ok] ;
	if(k == K) return 0 ;
	if(ok){
		int ans = 0 ;
		ans = max(solve(i+1,j,k+1,0),solve(i,j+1,k+1,0)) ;
		if(s[i] == t[j]){
			ans = max(ans,1+solve(i+1,j+1,k,1)) ;
			ans = max(ans,1+solve(i+1,j+1,k+1,0)) ;
		}
		dp[i][j][k][ok] = ans ;
	} else {
		int ans = 0 ;
		ans = max(solve(i+1,j,k,0) , solve(i,j+1,k,0)) ;
		if(s[i] == t[j]){
			ans = max(ans,1+solve(i+1,j+1,k,1)) ;
			ans = max(ans,1+solve(i+1,j+1,k+1,0)) ;
		}
		dp[i][j][k][ok] = ans ;
	}
	return dp[i][j][k][ok] ;
}
int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n >> m >> K ;
	cin >> s >> t ;
	cout << solve() ;
	return 0 ;
}

