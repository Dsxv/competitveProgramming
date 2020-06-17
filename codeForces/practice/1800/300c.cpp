#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
const int N = 2e6 + 10 ;

int fact[N] ;

int modexp(int a , int n){
	if(n == 0) return 1; 
	if(n == 1) return a; 
	int x = modexp(a , n /2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++) fact[i] = (fact[i-1]*i) % mod ;
	int a, b , n ;
	cin >> a >> b >> n ;
	int ans = 0 ;
	set<int> xa , xb , xc ;
	xa.insert(a) ; xc.insert(a) ;
	xb.insert(b) ; xc.insert(b) ;
	for(int i = n ; i >= 0 ; i--){
		int val = i*a + (n-i)*b ;
		set<int> s ;
		int tp = val ;
		while(val){
			s.insert(val%10) ;
			val /= 10 ;
		}
		if(s == xa || s == xb || s == xc){
			int f = fact[n]*modexp(fact[i] , mod - 2)  ;
			f %= mod ;
			f = (f*modexp(fact[n-i] , mod-2)) % mod ;
			ans = (ans +f ) % mod ;
		}
	}
	cout << ans ;
	return 0 ;
}

