#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int x , y ;
		cin >> x >> y ;
		int n = max(x,y) ;
		int ans = (n-1)*(n-1) ;
		if(n&1) swap(x,y) ;
		if(x < y) {
			cout << ans + x << '\n' ;
		} else {
			cout << ans + n + (n - y) << '\n' ;
		}
	}
	return 0 ;
}

