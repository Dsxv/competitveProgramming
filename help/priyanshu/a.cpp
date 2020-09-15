#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int tmp = 1e6 + 20 ;
int32_t main(){
	int n , m  , k ;
	cin >> n >> m >> k ;
	int a[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++) 
			cin >> a[i][j] ;
	}
	int dp[n][m] ;
	dp[0][0] = a[0][0] ;
	int cnt = a[0][0] <= k ;
	for(int i = 1 , j = 0; i < n ; i++) {
		dp[i][j] = a[i][j]*dp[i-1][j] ;
		dp[i][j] = min(tmp , dp[i][j]) ; 
		cnt += dp[i][j] <= k ;
	}
	for(int j = 1 , i = 0 ; j < m ; j++){
		dp[i][j] = a[i][j]*dp[i][j-1] ;
		dp[i][j] = min(tmp , dp[i][j]) ;
		cnt += dp[i][j] <= k ;
	}
	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < m ; j++){
			if(dp[i-1][j-1] == 0 || dp[i][j-1] == 0 || dp[i-1][j] == 0){
				dp[i][j] = 0 ;
			} else {
				dp[i][j] = min(tmp , a[i][j]*(dp[i-1][j]*dp[i][j-1]  / dp[i-1][j-1])) ;
			}
			cnt += dp[i][j] <= k ;
		}
	}
	cout << cnt ;
	return 0 ;
}

