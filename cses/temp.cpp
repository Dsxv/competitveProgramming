#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
const int mod = 1e9 + 7 ;
int dp[N] ;

int f(int n){
	if(n == 0) return 1 ;
	if(n < 0) return 0 ;
	if(~dp[n]) return dp[n] ;
	int ans = 0 ;
	for(int j = 1 ; j <= 6 ; j++){
		ans = (ans + f(n-j)) % mod ;
	}
	return dp[n] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int n ; cin >> n ;
	cout << f(n) ;
	return 0 ;
}

