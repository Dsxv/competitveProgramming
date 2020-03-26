#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
 
const int N = 1e6 + 4 ;

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

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		update(i+1,x) ;
	}
	int q ; cin >>  q;
	while(q--){	
		char ch ;
		cin >> ch ;
		if(ch == 'q'){
			int l , r ;
			cin >> l >> r ;
			cout << query(r) - query(l-1) << '\n' ;
		} else {
			int i , x ;
			cin >> i >> x ;
			update(i,x) ;
		}
	}
	return 0 ;
}

