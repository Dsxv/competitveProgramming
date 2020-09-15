#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
const int N = 1e6 ;
int fact[N]  ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		fact[i] = (fact[i-1]*i) % mod ;
	}
	int n , m ;
	cin >> n >> m ;
	auto ncr = [&](int n , int r) -> int {
		return (((fact[n]*modexp(fact[r] , mod - 2)) % mod) * modexp(fact[n-r],mod -2) ) % mod ;
	} ;
	int x = ( fact[n]*ncr(m,n) ) % mod ;
	int y = x ;
	for(int i = 1 ; i <= n ; i++){
		int val = ncr(n,i)*ncr(m-i,n-i) ; val %= mod ;
		val = (val*fact[n-i]) % mod ;
		if(i&1) y = ( y - val + mod ) % mod ;
		else y = (y + val) % mod ;
	}
	cout << ( x * y ) % mod ;
	return 0 ;
}
