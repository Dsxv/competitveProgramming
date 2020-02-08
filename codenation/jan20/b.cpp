#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 , mod = 1e9 + 7;
int a[N] , fact[N];

int modexp(int a , int n){
	if(n == 0){
		return 1 ;
	}
	if(n == 1){
		return a ;
	}
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int n ;
	cin >> n ;
	fact[0] = 1 ;
	for(int i = 1 ; i <= n ; i++) fact[i] = (fact[i-1]*i) % mod ;
	a[0] = 0 ;
	for(int i = 1 ; i <= n ; i++){
		a[i] = ((i*a[i-1])%mod +  fact[i-1]) % mod ;
	}
	cout << (a[n]*modexp(fact[n],mod-2)) % mod ;
	return 0 ;
}

