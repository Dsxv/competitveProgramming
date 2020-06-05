#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
const int mod = 998244353 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n /2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	int a[N] = {} ;
	for(int i = 1 ; i < N ; i++){
		int x = i ;
		int val = 0 ;
		while(x%2 == 0){
			x /= 2 ;
			val++ ;
		}
		val = (1LL<<val) ;
		a[i] = modexp(i,val) ;
	}
	int pre[N] = {} ;
	for(int i = 1 ; i < N ; i++){
		pre[i] = (a[i] + pre[i-1]) % mod ;
	}
	while(t--){
		int n ;
		cin >> n ;
		cout << pre[n] << '\n' ;
	}
	return 0 ;
}

