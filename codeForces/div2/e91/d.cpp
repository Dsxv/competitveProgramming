#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	int x , k , y ;
	cin >> x >> k >> y ;
	int a[n+2] = {} ; int b[m] ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int j = 0 ; j < m ; j++) cin >> b[j] ;
	int dp[n+2] = {} ;
	int l = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(l < m && a[i] == b[l]){
			l++ ;
			continue ;
		}
		dp[i] = 1 ;
	}
	vector<pair<int,int>> region ;
	bool br = false ;
	for(int i = 0 ; i <= n ; i++){
		if(!dp[i]) {
			br = true ;
			continue ;
		}
		if(br){
			region.push_back({i,i}) ;
			br = false ;
		} else {
			region.back().second++ ;
		}
	}
	bool ok = true ;
	int ans = 0 ;
	for(auto r : region){
		bool big = false ;
		int mx = max(a[r.first - 1] , a[r.second + 1]) ;
		for(int i = r.first ; i <= r.second ; i++){
			if(a[i] > mx) big = true ;
		}
		int sz = r.second - r.first + 1 ;
		if(sz < k){
			if(big){
				ok = false ;
				break ;
			}
			ans += sz*y ;
		} else {
			if(x <= y*k){
				ans += (sz/k)*x + (sz - (sz/k)*k)*y ;
			} else {
				if(!big){
					ans += sz*y ;
				} else {
					ans += (sz-k)*y + x ;
				}
			}
		}
	}
	if(!ok || (l != m)) {
		cout << -1 ;
		return 0 ;
	}
	cout << ans ;
	return 0 ;
}

