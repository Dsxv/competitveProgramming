#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		bool found = true ;
		for(int i = 0 ; i < n ; i++){
			if((i+1) % a[i] != 0) found = false ;
		}
		cout << (found ? "YES" : "NO" ) << '\n' ;
	}
	return 0 ;
}

