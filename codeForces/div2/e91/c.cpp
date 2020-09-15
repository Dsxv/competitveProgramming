#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		sort(a,a+n) ;
		int dp[n+1] = {} ;
		for(int i = n - 1 ; i >= 0 ; i--){
			int lo = i , hi = n - 1 ;
			int ans = -1 ;
			while(lo <= hi){
				int mid = lo + hi >> 1 ;
				if(a[i]*(mid - i + 1) >= x){
					ans = mid ;
					hi = mid - 1 ;
				} else {
					lo = mid + 1 ;
				}
			}
			if(~ans){
				dp[i] = 1 + dp[ans+1] ;
			}
		}
		cout << *max_element(dp , dp + n) << '\n' ;
	}
	return 0 ;
}

