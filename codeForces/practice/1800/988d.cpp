#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n;
	cin >> n ;
	int a[n] ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		mp[a[i]]++ ;
	}
	vector<int> cur , ans ;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < 31 ; j++){
			cur.clear() ;
			cur.push_back(a[i]) ;
			if(mp.count(a[i] - (1LL<<j))) cur.push_back(a[i] - (1LL<<j)) ;
			if(mp.count(a[i] + (1LL<<j))) cur.push_back(a[i] + (1LL<<j)) ;
			if(ans.size() < cur.size()){
				ans = cur ;
			}
		}
		if(ans.size() == 3) break ;
	}
	cout << ans.size() << '\n' ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

