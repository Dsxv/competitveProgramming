#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<pair<int,int>> p ;
		int a[n] ;
		for(int i = 0 ; i < n; i++) {
			cin >> a[i] ;
			if(!a[i]) continue ;
			p.push_back({a[i],i}) ;
		}
		int ans[n] = {} ;
		for(int i = 0 ; i < n ; i++) ans[i] = 1 ;
		sort(p.begin(),p.end()) ;
		if(p[0].first > 0){
			ans[p[0].second] = 0 ;
		} else {
			int ind = 0 ;
			while(p[ind].first < 0){
				ans[p[ind].second] = 0 ;
				ind++ ;
			}
			if(p[ind].first > -p[ind-1].first){
				ans[p[ind-1].second] = 1 ;
			} else {
				ans[p[ind].second] = 0 ;
			}
		}
		int val = 0 ;
		for(int i = 0 ; i < n ; i++){
			if(ans[i]) val += a[i] ;
		}
		cout << val << '\n' ;
		for(int i = 0 ; i < n ; i++){
			cout << ans[i]  ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

