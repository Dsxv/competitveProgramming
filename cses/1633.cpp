#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int dp[n+1] = {} ;
	dp[0] = 1 ;
	int mod = 1e9 + 7 ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i - 1 ; j >= i - 6 && j >= 0 ; j--){
			dp[i] += dp[j] ;
			dp[i] %= mod ;
		}
	}
	cout << dp[n] ;
	return 0 ;
}

