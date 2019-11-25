#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int dp[n] ;
	dp[0] = a[0] ;
	if(n > 1) dp[1] = a[0] + a[1] ;
	if(n > 2) dp[2] = max(dp[1],a[0]+a[2]) ;
	for(int i = 3 ; i < n ; i++){
		dp[i] = max({dp[i-1],dp[i-2]+a[i],dp[i-3]+a[i-1]+a[i]}) ;
	}
	cout << accumulate(a,a+n,0LL) - dp[n-1] ;
	return 0 ;
}

