#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

const int N = 2e5 + 10 ;

int t[4*N] ;

void build(int* a , int v , int tl , int tr){
	if(tl == tr){
		t[v] = a[tl] ;
	}else{
		int tm = (tl+tr)/2 ;
		build(a, 2*v, tl, tm) ; build(a, 2*v+1, tm+1, tr) ;
		t[v] = max(t[2*v], t[2*v+1]) ;
	}
}

int query(int v , int tl , int tr , int l , int r){
	if(l > r){
		return 0 ;
	}
	if(tl == l && tr == r){
		return t[v] ;
	}
	int tm = (tl + tr) / 2 ;
	return max(query(2*v, tl, tm, l, min(r,tm)) 
		, query(2*v + 1, tm + 1, tr, max(l,tm+1), r) ) ;
}

void update(int v , int tl , int tr , int pos , int new_val){
	if(tl == tr){
		t[v] = new_val ;
	}else{
		int tm = (tl + tr) / 2 ;
		if(pos <= tm) // left jao
			update(2*v, tl, tm, pos, new_val) ;
		else 
			update(2*v + 1, tm+1, tr, pos, new_val) ;
		t[v] = max(t[2*v] , t[2*v + 1]);
	}
}


int32_t main(){
	int tc ;
	cin >> tc ;
	while(tc--){
		ordered_set s ;
		for(int i = 0 ; i < 4*N ; i++) t[i] = 0 ;
		int n ; 
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			s.insert(a[i]) ;
		}
		for(int i = 0 ; i < n ; i++) a[i] = s.order_of_key(a[i]) ;
		build(a,1,0,n-1) ; // segtree from 1 index
		vector<int> ans(n) ;
		for(int i = n-1 ; i >= 0 ; i--) {
			int ind = query(1,0,n-1,a[i],a[i]) ;
			update(1,0,n-1,a[i],max(ind,i)) ;
			ans[i] = max(0LL,query(1,0,n-1,0,a[i]-1) - i) ;
		}
		for(auto  i : ans) cout << i << " " ;
		cout << endl ;
	}
	return 0 ;
}



