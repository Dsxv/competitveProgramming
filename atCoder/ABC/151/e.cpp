#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 , mod = 1e9 + 7 ;
int fact[N] ;

int modexp(int a , int n ){
	if(n == 0) return 1 ;
	if(n == 1 ) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int solve(int n , int k){
	int ans = (fact[n]*modexp(fact[k],mod-2)) % mod ;
	ans = ans*modexp(fact[n-k],mod-2) ;
	return (ans%mod) ;
}

int32_t main(){
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++) {
		fact[i] = (fact[i-1]*i) % mod ;
	}
	int n , k;
	cin >> n >> k;
	int a[n+1] ;
	a[0] = INT_MIN ; 
	for(int i = 0 ; i < n ; i++){
		cin >> a[i+1] ;
	}
	sort(a,a+n) ;
	int ans = 0 ;
	for(int i = k;  i <= n ; i++){
			ans = (ans + (a[i]*solve(i-1,k-1)) % mod) % mod ;
	}
	
	int ans2 = 0 ;
	for(int i = 1 ; i <= (n / 2) ; i++) swap(a[i],a[n-i+1]) ;
	for(int i = k ; i <= n ; i++){
		int x = (a[i]*solve(i-1,k-1))%mod ;
		ans2 = (ans2 + x ) % mod ;
	}
	cout << (ans - ans2 + mod ) % mod ;
	return 0 ;
}

