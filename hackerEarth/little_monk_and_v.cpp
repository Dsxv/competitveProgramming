#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update> ordered_set  ;

typedef tree<pair<int,int> , null_type , less<pair<int,int>> , rb_tree_tag,
		tree_order_statistics_node_update> ordered_multiset ;

int32_t main(){
	/* ordered set 
	 * ordered_set s ;
	 * s.order_of_key(10) // gives index of value 10 in set
	 * if not present then tells where it will be.
	 * (*s.find_by_order(7)) // gives value at index 7
	*/
	/* ordered_multiset
	 * ordered_multiset s;
	 * int t = 0 ;
	 * s.insert({x,t++}) ; // t is time
	 * s.order_of_key({10,0}) // gives first index of value 10 
	 * s.find_by_order(10)->first // element at index 10
	 * s.erase(s.lower_bound({10,0})) ; value 10 erased
	*/
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	ordered_multiset s ;
	int n ;
	cin >> n ;
	int a[n] = {} ;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < n ; j++){
			int x ;
			cin >> x ;
			a[j] += x ;
		}
	}
	int t = 0 ;
	for(auto i : a){
		s.insert({i,t++}) ;
	}
	int q ;
	cin >> q ;
	while(q--){
		int x ;
		cin >> x ;
		if(s.size() < x){
			cout << -1 << '\n' ;
		} else {
			x-- ;
			auto k = s.find_by_order(x) ;
			cout << k->first << '\n' ;
			s.erase(k) ;
		}
	}

	return 0 ;
}


