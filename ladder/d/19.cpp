#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

int32_t main(){
	int n ;
	cin >> n ;
	int dp[n] ;
	int p[n] ;
	for(int i = 0 ; i < n ; i++) {
		int x ; cin >> x ;
		p[i] = x - 1 ;
	}	
	for(int i = 0 ; i < n ; i++){
		dp[i] = 2 ;
		for(int j = p[i] ; j < i ; j++) {
			dp[i] = (dp[i] + dp[j]) % mod ;
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans = (ans + dp[i]) % mod ;
	}
	cout << ans ;	
	return 0 ;
}

