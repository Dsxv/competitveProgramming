#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x ;
		string s ;
		cin >> s ;
		if(x < 0){
			for(int i = 0 ; i < n ; i++){
				if(s[i] == '0') s[i] = '1' ;
				else s[i] = '0' ;
			}
		}
		x = abs(x) ;
		int a[n] = {} ;
		int count = 0 ;
		int z = 0 , o = 0 ;
		for(int i = 0 ; i < n ; i++) {
			if(s[i] == '0') count++ , z++ ;
			else count-- , o++;
			a[i] = count ;
		}
		int d = z - o ;
		int ans = 0 ;
		if(d <= 0){
			for(int i = 0 ; i < 2*n ; i++){
				ans += ((a[i] + (i/n)*d) == x) ;
			}
			if(d == 0 && ans){
				cout << -1 << endl ;
				continue ;
			}
			ans += (x == 0) ;
		} else {			
			if(x == 0) ans++ ;
			int val = 0 ;
			int temp = x ;
			if(x > d) {
				x -= d ;
				x /= d ;
				val = x*d;
			}
			x = temp ;
			for(int i = 0 ; i < 3*n ; i++) {
				ans += ((a[i] + val) == x) ;
				if(i == n || i == 2*n) val+=d ;
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}

