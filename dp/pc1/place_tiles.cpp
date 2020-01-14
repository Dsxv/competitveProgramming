#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int32_t main(){
	int n ;
	cin >> n ;
	int dp[n+1] ;
	dp[1] = 1 , dp[2] = 2 ;
	for(int i = 3 ; i <= n ; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % mod ;
	}
	cout << dp[n] ;
	return 0 ;
}

