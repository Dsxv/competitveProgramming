#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n+2] = {} ;
		for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
		int mx = 0 , mn = 1e9 ;
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == -1) continue ;
			if(a[i-1] == -1 || a[i+1] == -1){
				mx = max(mx , a[i]) ;
				mn = min(mn , a[i]) ;
			}
		}
		int val = (mn + mx) / 2 ;
		for(int i = 1 ; i <= n ; i++) {
			if(~a[i]) continue ;
			a[i] = val ;
		}
		int ans = 0 ;
		for(int i = 1 ; i < n ; i++){
			ans = max(ans , abs(a[i] - a[i+1])) ;
		}
		cout << ans << " " << val << '\n' ;
	}
	return 0 ;
}

