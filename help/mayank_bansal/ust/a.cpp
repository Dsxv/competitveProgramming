#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int modexp(int a  , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x * x) % mod ;
	if(n&1) x = (x * a) % mod ;
	return x ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n;
		cin >> n ;
		if(n == 1){
			cout << 0 << '\n' ;
			continue ;
		}
		cout << (modexp(2 , n) - 2 + mod) % mod << '\n' ;
	}
	return 0 ;
}

