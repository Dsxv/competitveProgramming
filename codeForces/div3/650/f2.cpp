#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<pair<int,int>, null_type , less<pair<int,int>> , rb_tree_tag,
            tree_order_statistics_node_update> ordered_set  ;


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		ordered_set oset ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			oset.insert({a[i],i}) ;
		}
		for(int i = 0 ; i < n ; i++) {
			a[i] = oset.order_of_key({a[i],i}) + 1 ;
		}
		vector<int> v[n+1] ;
		int ans[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			int cur = 0 ;
			if(v[a[i]-1].size()) {
				cur = max(cur , ans[v[a[i]-1].back()]) ;
			}
			ans[i] = cur + 1 ;
			v[a[i]].push_back(i) ;
		}
		//for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
		cout << n - *max_element(ans , ans + n) << '\n' ;
	}
	return 0 ;
}


