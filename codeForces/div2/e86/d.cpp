#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<pair<int,int>, null_type , less<pair<int,int>> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	ordered_set s ;
	int n , k ;
	cin >> n >> k ;
	int t = 0 ; 
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		s.insert({x,t++}) ;
	}
	int pre[k] , c[k] ;
	for(int i = 0 ; i < k ; i++) cin >> c[i] ;
	pre[0] = c[0] ;
	for(int i = 1 ; i < k ; i++) {
		pre[i] = min(pre[i-1], c[i]) ;
	}
	vector<vector<int>> ans ;
	vector<int> cur ;
	while(s.size()){
		int sz = cur.size() + 1 ;
		int lo = 0 , hi = (int)s.size() - 1 ;
		int id = -1 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(pre[(s.find_by_order(mid)->first)-1] >= sz){
				id = mid ;
				lo = mid + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		if(id == -1){
			ans.push_back(cur) ;
			cur.clear() ;
		} else {
			auto y = s.find_by_order(id) ;
			cur.push_back(y->first) ;
			s.erase(y) ;
		}
	}
	if(cur.size()) ans.push_back(cur) ;
	cout << ans.size() << '\n';
	for(auto i : ans){
		cout << i.size() << " " ;
		for(auto j : i) cout << j << " " ;
		cout << '\n' ;
	}
	return 0 ;
}


