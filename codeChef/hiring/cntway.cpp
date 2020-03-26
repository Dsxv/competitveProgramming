#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ;

const int mod = 1e9 + 7 ;


int dp[N] ;
int n , l ;

int solve(int i){
	if(i < 2){
		return i == 0 ;
	}
	if(dp[i] != -1) return dp[i] ;
	int ans = 0 ;
	for(int j = 2 ; j <= l ; j+=2){
		ans = (ans + solve(i-j)) % mod ;
	}
	return dp[i] = ans ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp,-1,sizeof(dp)) ;
		cin >> n >> l ;
		cout << solve(n) << '\n' ;
	}
	return 0 ;
}

