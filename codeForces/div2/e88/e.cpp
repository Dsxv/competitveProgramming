#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e5 + 10 ;
const int mod = 998244353 ;

int fact[N] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2 ) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int ncr(int n , int r){	
	int val = (fact[n] * modexp(fact[r] , mod - 2) ) % mod ;
	val = ( val * modexp(fact[n-r] , mod - 2) ) % mod ;
	return val ;
}

int32_t main(){
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		fact[i] = (i*fact[i-1]) % mod ;
	}
	int n , k ;
	cin >> n >> k ;
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		int r = (n-i)/i ;
		if(r < (k-1)) continue ;
		ans = (ans + ncr(r,k-1)) % mod ;
	}
	cout << ans ;
	return 0 ;
}

