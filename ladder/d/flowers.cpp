#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
const int mod = 1e9 + 7 ;
int dp[N] ;

int32_t main(){
	int t , k ;
	cin >> t >> k;
	dp[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		dp[i] = (dp[i-1] + ((i-k >=0) ? dp[i-k] : 0))%mod ;
	}
	for(int i = 2 ; i < N ; i++){
		dp[i] = (dp[i] + dp[i-1])%mod ;
	}
	dp[0] = 0 ;	
	while(t--){
		int a , b ;
		cin >> a >> b ;
		cout << (dp[b] - dp[a-1] + mod)%mod << '\n';
	}
	return 0 ;
}

