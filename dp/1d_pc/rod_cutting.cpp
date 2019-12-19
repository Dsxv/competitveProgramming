#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 20 ;
int dp[N] ;

int solve(int* a , int n){
	if(n == 1) return a[1] ;
	if(dp[n] != -1) return dp[n] ;
	int ans = a[n] ;
	for(int i = 1 ; i < n ; i++){
		ans = max(ans, a[i] + solve(a,n-i)) ;
	}
	return dp[n] = ans ;
}


int32_t main(){
	int n ;
	cin >> n ;
	int a[n+1] ;
	for(int i = 0 ; i < n + 1 ; i++) dp[i] = -1 ;
	for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
	cout << solve(a,n) ;
	return 0 ;
}

