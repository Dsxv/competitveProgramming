#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int od = 0 ;
		for(int i = 0 ; i < n ; i++) {
			int x ; cin >> x ;
			od += (x % 2) ;
		}
		if(od){
			if(od == n && (n%2 == 0)) {
				cout << "NO\n" ;
			}
			else cout << "YES\n" ;
		} else {
			cout << "NO\n" ;
		}
	}
			
	return 0 ;
}

