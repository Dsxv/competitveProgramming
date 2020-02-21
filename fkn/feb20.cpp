#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int dp[n][n] = {} , a[n][n];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> a[i][j] ;
		}
	}
	dp[n-1][n-1] = a[n-1][n-1] ;
	for(int i = n - 2 ; i >= 0 ; i--){
		dp[i][n-1] = max(dp[i+1][n-1] + a[i][n-1],a[i][n-1]) ;
		dp[n-1][i] = max(dp[n-1][i+1] + a[n-1][i] , a[n-1][i]) ;
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		for(int j = n - 2 ; j >= 0 ; j--){
			dp[i][j] = max({a[i][j] , a[i][j] + dp[i+1][j] , a[i][j] + dp[i][j+1]}) ;
		}
	}
	int mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			mx = max(mx,dp[i][j]) ;
		}
	}
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			count += dp[i][j] == mx ;
		}
	}
	cout << mx << " " << count ;
	return 0 ;
}

