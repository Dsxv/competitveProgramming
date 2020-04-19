#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int x , n , m ;
		cin >> x >> n >> m ;
		while(x > 20 && n){
			x /= 2 ;
			x += 10 ;
			n-- ;
		}
		while(x > 0 && m){
			x -= 10 ;
			m-- ;
		}
		if(x > 0) cout << "NO\n" ;
		else cout << "YES\n" ;
	}
	return 0 ;
}

