#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
const int mod = 998244353 ;

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
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		fact[i] = (fact[i-1]*i) % mod ;
	}
	int n , m ;
	cin >> n >> m ;
	int f = ((fact[m]*modexp(fact[m-n+1],mod-2))%mod*(modexp(2,n-3)))%mod ;
	f = (f*modexp(fact[n-1],mod-2))%mod ;
	f = (f*(n-2))%mod ;
	cout << f ;
	return 0 ;
}

