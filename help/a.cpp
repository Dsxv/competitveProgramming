#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
const int N = 1e6 ;
int fib[N] ;

int modexp(int a , int n ){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp( a , n / 2) ;
	x = ( x * x ) % mod ;
	if(n & 1) x = (x * a) % mod ;
	return x ;
}

int ncr(int n , int r){
	int x = 1 , y = 1 ;
	if(n < r) return 0 ;
	for(int i = n ; i > (n - r) ; i--){
		x = ( x * i ) % mod ;
	}
	for(int i = r ; i > 0 ; i--){
		y = (y * i) % mod ;
	}
	return (x * modexp(y , mod - 2) ) % mod ;
}

int32_t main(){
	int v , m , x ;
	cin >> v >> m >> x ;
	fib[1] = 2 ;
	fib[2] = 3 ;
	for(int i = 3 ; i <= x ; i++) fib[i] = fib[i - 1] + fib[i - 2] ; 
	int ans = 0 ;
	for(int i = m ; i <= x ; i++){
		ans += ncr(fib[i] , v) ;
		ans %= mod ;
	}
	cout << ans ;
	return 0 ;
}

