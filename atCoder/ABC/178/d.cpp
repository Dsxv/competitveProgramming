#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 10 ;
const int mod = 1e9 + 7 ;

int dp[N] ;
int n ;
int solve(int i = 0){
	if(i > n) return 0 ;
	if(i == n){
		return 1 ;
	}
	if(~dp[i]) return dp[i] ;
	int ans = 0 ;
	for(int j = 3 ; j <= n ; j++){
		ans = (ans + solve(i + j)) % mod ;
	}
	return dp[i] = ans ;
}

int32_t main(){
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	cout << solve() ;
	return 0 ;
}

