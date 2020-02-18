#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 + 10 ;
const int mod = 1e9 + 7 ;
int fact[N] ;
int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int t ;
	cin >> t ;
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		fact[i] = (fact[i-1]*i) % mod ;
	}
	while(t--){
		int n , k ;
		cin >> n >> k ;
		if(k == 1){
			cout << fact[n] << '\n' ;
			return 0 ;
		} else {
			int x = modexp(k,n-1) ;
			cout << x << endl ;
		}
	}
	return 0 ;
}

