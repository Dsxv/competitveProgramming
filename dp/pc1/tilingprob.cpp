#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;

int dp[N] ;

int solve(int n){
	if(n == 0) return 1 ;
	if(n < 0) return 0 ;
	if(dp[n] != -1) return dp[n] ;
	return dp[n] = solve(n-4) + solve(n-1) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i <= n ; i++) dp[i] = -1 ;
	cout << solve(n) ;
	return 0 ;
}

