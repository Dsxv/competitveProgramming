#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m , q ;
		cin >> n >> m >> q ;
		int a[n] = {0} , b[m] = {0} ;
		while(q--){
			int x , y ;
			cin >> x >> y ;
			x-- , y-- ;
			a[x]++ , b[y]++ ;
		}
		int odd = 0 ;
		for(auto i : b) odd += i%2 ;
		long long ans = 0 ;
		for(auto i : a){
			if(i%2) ans += m-odd ;
			else ans += odd ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

