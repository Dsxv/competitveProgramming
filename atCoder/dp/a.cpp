#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int dp[n] = {} ;
	dp[0] = 0 ;
	for(int i = 1 ; i < n ; i++){
		dp[i] = LLONG_MAX ;
		for(int j = i - 1 ; j >= 0 && j >= i - k ; j--){
			dp[i] = min(dp[j] + abs(a[j] - a[i]) , dp[i]) ;
		}
	}
	cout << dp[n-1] ;
	return 0 ;
}

