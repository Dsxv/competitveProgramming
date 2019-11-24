#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int N = 50 ;
		int dp[N] = {0} ;
		dp[0] = 0 ;
		dp[1] = 1 ;
		dp[2] = 2 ;
		for(int i = 3 ; i <= n ; i++){
			dp[i] = dp[i-2]*(i-1) + dp[i-1] ;
		}
		cout << dp[n] << '\n' ;
	}
	return 0 ;
}

