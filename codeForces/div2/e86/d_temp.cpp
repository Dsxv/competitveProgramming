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
	ordered_set s ;
	int n ;
	cin >> n ;
	int t = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		s.insert({x,t++}) ;
	}
	s.erase(s.find_by_order(4)) ;
	for(auto i : s) cout << i.first << " " ;
	return 0 ;
}


