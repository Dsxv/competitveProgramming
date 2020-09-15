#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
		}
		sort(a,a+n) ;
		int q ; cin >> q ;
		while(q--){
			int x , y ;
			cin >> x >> y ;
			int lo = 0 , hi = n - 1 ;
			int ans = 0 ;
			while(lo <= hi){
				int mid = (lo + hi) / 2 ;
				int val = x + y - a[mid] ;
				if(val == 0) {
					ans = -1 ; break ;
				}
				if(val > 0){
					ans = mid + 1 ;
					lo = mid + 1 ;
				} else {
					hi = mid - 1 ;
				}
			}
			cout << ans << '\n' ;
		}
	}
	return 0 ;
}

