#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		bool ok = true ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			ok &= x&1 ;
		}
		cout << (ok ? "YES" : "NO") << '\n' ;
	}
	return 0 ;
}

