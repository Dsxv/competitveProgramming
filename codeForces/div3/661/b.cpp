#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++) cin >> b[i] ;
		int x = *min_element(a,a+n) ;
		int y = *min_element(b,b+n) ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			int r = a[i] - x , s = b[i] - y ;
			int x = min(r,s) ;
			r -= x , s -= x ;
			ans += r + s + x ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

