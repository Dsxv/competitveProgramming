#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x * x) % mod ;
	if(n & 1) x = (x * a) % mod ;
	return x ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int dp[2] = {0 , 1} ;
	for(int i = 2 ; i <= n ; i++){
		dp[i % 2] = (dp[i % 2] + dp[1 - i % 2]) % mod ;
	}
	int x = modexp(2 , n) ;
	cout << (dp[n % 2] * modexp(x , mod - 2)) % mod ;
	return 0 ;
}

