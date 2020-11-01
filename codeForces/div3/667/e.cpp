#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t; 
	cin >> t ;
	while(t--){
		int n , k;
		cin >> n >> k ;
		int a[n] , tp ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		sort(a , a + n) ;
		for(int i = 0 ; i < n ; i++) cin >> tp ;
		int dp[n+1] = {} ;
		for(int i = n - 1 ; i >= 0 ; i--){
			int ans = i ;
			int lo = i , hi = n - 1 ;
			while(lo <= hi){
				int mid = lo + hi >> 1 ;
				if(a[i] + k >= a[mid]) {
					ans = mid ;
					lo = mid + 1 ;
				} else {
					hi = mid - 1;
				}
			}
			dp[i] = max(ans - i + 1 , dp[i+1]) ;
		}
		int mx = 0 ;
		for(int i = 0 ; i < n ; i++){
			int ans = i ;
			int lo = i , hi = n - 1 ;
			while(lo <= hi){
				int mid = lo + hi >> 1 ;
				if(a[i] + k >= a[mid]){
					ans = mid ;
					lo = mid + 1 ;
				} else {
					hi = mid - 1 ;
				}
			}
			mx = max(mx , dp[ans + 1] + ans - i + 1) ;
		}
		cout << mx << '\n' ;
	}
	return 0 ;
}

