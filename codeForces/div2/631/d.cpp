#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[32] ;

int solve(int i ,int n ,int mod){
	//if at i , I am setting the ith bit on
	int l = max(0LL,(1LL<<(i-1))) , r = min(1LL<<i,n) ;
	if(~dp[i]) return dp[i] ;
	int val = r - l;
	if(val <= 0){
		return 0 ;
	}
	int ans = 1 ;
	for(int j = i + 1 ; j < 32 ; j++){
		ans = (ans + solve(j,n,mod))%mod ;
	}
	return dp[i] = (val*ans) % mod ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp, -1 , sizeof(dp)) ;
		int n , mod ;
		cin >> n >> mod ;
		int ans = 0 ;
		for(int i = 0 ; i < 32 ; i++){
			ans = (ans + solve(i,n,mod)) % mod ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}

