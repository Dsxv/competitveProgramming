#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int o = 0 ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			o += (x&1) ;
		}
		if(o == 0 || o == n) cout << "YES\n" ;
		else cout << "NO\n" ;
	}
	return 0 ;
}

