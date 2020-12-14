#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		vector<int> cnt[n + 1] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			cnt[a[i]].push_back(i) ;
		}
		int ans = INT_MAX ;
		for(int i = 1 ; i <= n ; i++){
			if(!cnt[i].size()) continue ;
			int cur = 0 ;
			int prev = -1 ;
			for(auto j : cnt[i]) {
				cur += (prev + 1) != j ;
				prev = j ;
			}
			if(cnt[i].back() != (n - 1)) cur++ ;
			ans = min(ans , cur) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

