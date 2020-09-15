#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int dp[n+1][m+1] = {} ;
	char ch[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) cin >> ch[i][j] ;
	}
	int mod = 1e9 + 7 ;
	dp[n-1][m-1] = ch[n-1][m-1] != '#';
	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = m - 1 ; j >= 0 ; j--){
			if(i == n - 1 && j == m - 1 || ch[i][j] == '#') continue ;
			dp[i][j] = (dp[i+1][j] + dp[i][j+1]) ;
			dp[i][j] %= mod ;
		}
	}
	cout << dp[0][0] ;
	return 0 ;
}

