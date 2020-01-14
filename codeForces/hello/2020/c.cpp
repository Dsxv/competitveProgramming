#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	if(n == 1) {
		cout << 1 ;
		return 0 ;
	}
	int fact[n+1] ;
	fact[0] = 1 ;
	for(int i = 1 ; i <= n ; i++) {
		fact[i] = (fact[i-1]*i) % m ;
	}
	int ans = 0 ;
	for(int i = n ; i >= 0 ; i--){
		ans = (ans + 2*i*fact[i]) % m;
	}
	cout << ans + 1;
	return 0 ;
}

