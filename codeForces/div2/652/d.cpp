#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e6 + 10 ;
const int mod = 1e9 + 7 ;

int dp[N] ;

int32_t main(){
	int toc0 = 0 , toc1 = 0 , tev0 = 0 , tev1 = 0 ;
	toc0 = 1 ;
	for(int i = 2 ; i < N ; i++){
		dp[i] = (dp[i-1] + 2*dp[i-2]) % mod ;
		if(i%3) continue ;
		dp[i]++ ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		cout << (dp[n])%mod << '\n' ;
	}
	return 0 ;
}

