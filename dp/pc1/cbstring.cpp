#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

const int N = 105 ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int dp[N+1] = {0} ;
		dp[0] = -1 , dp[1] = 2  , dp[2] = 3 ;
		for(int i = 3 ; i <= n ; i++) dp[i] = dp[i-1] + dp[i-2] ;
		cout << dp[n] << '\n' ;
	}
	return 0 ;
}

