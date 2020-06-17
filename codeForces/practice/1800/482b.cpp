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

struct Segtree{
	vector<int> t ;
	int n ;
	
	Segtree(){
		n = N ;
		t.resize(4*n) ;
	}

	Segtree(int l){
		n = l ;
		t.resize(4*n) ;
	}
	// v is current vertex in segtree , tl , tr in array
	void build_util(int* a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = a[tl] ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = (t[2*v] & t[2*v+1]) ;
		}
	}
	
	void build(int * a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	int query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return (1LL<<30) - 1;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return (query_util(2*v, tl, tm, l, min(r,tm)) 
			& query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	int query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}

	void update_util(int v , int tl , int tr , int pos , int new_val){
		if(tl == tr){
			t[v] = new_val ;
		}else{
			int tm = (tl + tr) / 2 ;
			if(pos <= tm) // left jao
				update_util(2*v, tl, tm, pos, new_val) ;
			else 
				update_util(2*v + 1, tm+1, tr, pos, new_val) ;
			t[v] = min(t[2*v] , t[2*v + 1]);
		}
	}
	
	void update(int pos , int val){
		 update_util(1,0,n-1,pos,val) ;
	}

} ;

struct queries{
	int l , r , x ;
} ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	queries q[m] ;
	int a[n+1][32] = {} ;
	for(int i = 0 ; i < m ; i++){
		cin >> q[i].l  >> q[i].r >> q[i].x ;
		q[i].l-- , q[i].r-- ;
		for(int j = 0 ; j < 30 ; j++){
			if((q[i].x>>j)&1){
				a[q[i].l][j] += 1 ;
				a[q[i].r+1][j] -= 1 ;
			}
		}
	}
	int ans[n] = {} ;
	for(int j = 0 ; j < 30 ; j++){
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			sum += a[i][j] ;
			ans[i] |= (sum>0)<<j ;
		}
	}
	Segtree seg(n) ;
	seg.build(ans , n) ;
	bool found = true ;
	for(int i = 0 ; i < m ; i++){
		if(seg.query(q[i].l , q[i].r) != q[i].x){
			found = false ;
		}
	}
	if(!found){
		cout << "NO" ;
	} else {
		cout << "YES\n" ;
		for(auto i : ans) cout << i << " " ;
	}
	return 0 ;
}

