#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , c ;
		cin >> n >> c ;
		pair<int,int> a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i].first ;
			a[i].second = i + 1 ;
		}
		sort(a , a + n) ;
		vector<int> ans ;
		int sum = 0 ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(sum + a[i].first <= c) {
				sum += a[i].first ;
				ans.push_back(a[i].second) ;
			}
		}
		if(sum >= (c + 1) / 2){
			cout << ans.size() << '\n' ;
			for(auto i : ans) cout << i << " " ;
			cout << '\n' ;
		} else {
			cout << -1 << '\n' ;
		}
	}

	return 0 ;
}

