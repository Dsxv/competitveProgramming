#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , s ;
	cin >> n >> s ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int dp[n+1][s+1] = {};
	for(int i = 0 ; i <= n ; i++) dp[i][0] = 1 ;
	for(int j = 1 ; j <= s ; j++) dp[0][j] = 0 ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= s ; j++){
			if(j - a[i] >= 0) dp[i][j] += dp[i-1][j- a[i]] ;
			dp[i][j] += dp[i-1][j] ;
		}
	}
	cout << (dp[n][s] ? "Yes" : "No") ;	
	return 0 ;
}

