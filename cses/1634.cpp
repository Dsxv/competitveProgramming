#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
int dp[N] ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n, x ;
	cin >> n >> x ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 1 ; i <= x ; i++){
		dp[i] = INT_MAX ;
	}
	dp[0] = 0 ;
	for(int i = 1 ; i <= x ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i-a[j] >= 0) dp[i] = min(dp[i-a[j]] + 1 , dp[i]) ;
		}
	}
	cout << (dp[x] >= INT_MAX ? -1 : dp[x])  ;
	return 0 ;
}

