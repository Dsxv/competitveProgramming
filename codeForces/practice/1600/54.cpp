#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		vector<pair<int,int>> start , end ;
		map<int,int> mp ;
		for(int i = 0 ; i < n ; i++){
			int x , y ;
			cin >> x >> y ;
			start.push_back({x,i}) ;
			mp[i] = y;
		}
		sort(start.begin() , start.end()) ;
		int mxd = mp[start[0].second] ;
		int id = -1 ;
		// calculate max endpt of a connected range
		// at any start if end pt of previous ones is less than 
		// current max range start pt 2 from there
		for(int i = 1 ; i < n ; i++){
			if(mxd < start[i].first){
				id = i ;
				break ;
			} else {
				mxd = max(mp[start[i].second] , mxd) ;
			}
		}
		if(id == -1){
			cout << -1 << '\n' ;
			continue ;
		}
		int ans[n] = {} ;
		for(int i = id ; i < n ; i++){
			ans[start[i].second] = 2 ;
		}
		for(int i = 0 ; i < n ; i++) if(!ans[i]) ans[i] = 1 ;
		for(auto i : ans) cout << i << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

