#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	int x ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		cin >> x ;
		mp[x]++ ;
	}
	vector<int> ans(m) ;
	for(int i = 0 ; i < m ; i++){
		cin >> x ;
		if(mp.size() == 0){
			ans[i] = -1 ;
		}
		auto it = mp.lower_bound(x) ;
		int val = it->first ;
		if(val == x){
			ans[i] = val ;
			mp[val]-- ;
			if(mp[val] == 0) mp.erase(val) ;
		} else {
			if(it == mp.begin()){
				ans[i] = -1 ;
			} else {
				it-- ;
				ans[i] = it->first ;
				mp[ans[i]]-- ;
				if(mp[ans[i]] == 0) mp.erase(ans[i]) ;
			}
		}
	}
	for(auto i : ans) cout << i <<' ';
	return 0 ;
}

