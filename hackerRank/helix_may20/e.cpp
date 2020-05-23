#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
 
const int N = 1e4 + 5 ;

int BIT[N] ;
int total ;
void update(int ind , int val){
    for(int i = ind ; i <= N ; i += i&-i){
        BIT[i] += val ;
    }
}
 
int query(int ind){
    int sum = 0 ;
    for(int i = ind ; i > 0 ; i -= i&-i){
        sum += BIT[i] ;
    }
    return sum ;
}

map<int,int> mp[N] ;
bool inv[N] ;
int32_t main(){
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	int n , q ;
	cin >> n >> q ;
	while(q--){
			int t ;
			cin >> t ;
			if(t == 1){
				cout << query(N-2) << '\n' ;
			} else if(t == 2){
				int i , j ;
				cin >> i >> j ;
				if(mp[i].count(j)){
					mp[i].erase(j) ;
					if(inv[i]){
						update(i,1) ;
					} else {
						update(i,-1) ;
					}
				} else {
					mp[i][j] = 1 ;
					if(inv[i]){
						update(i,-1) ;
					} else {
						update(i,1) ;
					}
				}
			} else {
				int i ; cin >> i ;
				int x = query(i) - query(i-1) ;
				inv[i] = !inv[i] ;
				update(i,-x) ;
				update(i,n-x) ;
			}
	}
	return 0 ;
}

