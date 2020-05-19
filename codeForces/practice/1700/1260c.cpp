#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int r, b, k ;
		cin >> r >> b >> k ;
		if(r < b) swap(r,b) ;
		cout << (((r-__gcd(r,b)-1)/b + 1) < k?"OBEY\n":"REBEL\n") ;
	}
	return 0 ;
}

