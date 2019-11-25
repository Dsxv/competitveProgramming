#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 , mod = 1e9 + 7 ;

int dp[N][2] ;

int32_t main(){
	int n ;
	cin >> n ;
	int p[n+1][2] ;
	for(int i = 1 ; i <= n ; i++){
		cin >> p[i][0] >> p[i][1] ;
	}
	for(int i = 1 ; i <= n ; i++){
		int e =  (p[i][0]%2 == 0) + (p[i][1]%2 == 0) ;
		int o =  p[i][0]%2 + p[i][1]%2 ; 
		if(i == 1){
			dp[i][1] = o ;
			dp[i][0] = e ;
			continue ;
		}
		dp[i][0] = (dp[i-1][0]*e + dp[i-1][1]*o)%mod ;
		dp[i][1] = (dp[i-1][0]*o + dp[i-1][1]*e)%mod ;
	}
	cout << dp[n][1] ;
	return 0 ;
}

