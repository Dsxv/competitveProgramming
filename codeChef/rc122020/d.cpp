#include <bits/stdc++.h>
using namespace std ;

#define int long long

int mod = 1e9 + 7 ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		if(n == 0){
			cout << ((k-1)*k) % mod << '\n' ;
			continue ;
		}
		if(k&1){
			int x = (n + (k-3)/2) ;
			int full = x*(x+1) ;
			full %= mod ;
			cout << (full + 2*(x+1) - n + mod ) % mod << '\n' ;
		} else {
			int x = (n + (k-2)/2) ;
			int full = x*(x+1) ;
			full %= mod ;
			cout << (full + n) % mod << '\n' ;
		}
	}
	return 0 ;
}

