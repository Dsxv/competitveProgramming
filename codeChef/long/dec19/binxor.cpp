#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
const int N = 2e5 ;
int fact[N] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1 ) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x)%mod ;
	if(n&1) x = (x*a)%mod ;
	return x ;
}

int32_t main(){
	fact[1] = fact[0] = 1 ;
	for(int i = 2 ; i < N - 2 ; i++) fact[i] = (fact[i-1]*i)%mod ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		string s1 , s2 ;
		cin >> s1 >> s2 ;
		int a, b, c, d ;
		a = b = c = d = 0 ;
		for(auto i : s1) {
			if(i == '0') a++ ;
			else b++ ;
		} 
		for(auto i : s2) {
			if(i == '0') c++ ;
			else d++ ;
		}
		int max_l = min(a,d) + min(b,c) ;
		int min_l = n - (min(a,c) + min(b,d)) ;

		int ans = 0 ;
		for(int i = min_l ; i <= max_l ; i += 2) {
			int x = fact[n]*modexp(fact[i],mod-2) ;
			x %= mod ;
			ans +=  ( x*modexp(fact[n - i], mod - 2) )%mod ;
			ans %= mod ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}

