#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
	int n , m ;
	cin >> n >> m ;
	int dp[n+1] = {0} ;
	for(int i = 0 ; i < m && i <= n; i++) dp[i] = 1 ;
	for(int i = m ; i <= n ; i++){
		dp[i] = (dp[i-1] + dp[i-m]) %mod ;
	}
	cout << dp[n] << '\n' ;
	}
	return 0 ;
}

