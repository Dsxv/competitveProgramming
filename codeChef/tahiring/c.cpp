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

struct st{
	int val , id , qual ;
	st(){
		val = id = qual = 0 ;
	}
	st(int x , int y , int z){
		val = x , id = y , qual = z ;
	}
} ;

st set_max(st a , st b){
	if(a.qual > b.qual) return a; 
	else return b ;
}

struct Segtree{
	vector<st> t ;
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
	void build_util(vector<st>& a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = a[tl] ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = set_max(t[2*v] , t[2*v+1]) ;
		}
	}
	
	void build(vector<st>& a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	st query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			st temp(0,0,0) ;
			return temp ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return set_max(query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	st query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}

	void update_util(int v , int tl , int tr , int pos , int new_val){
		if(tl == tr){
			t[v].val += new_val ;
		}else{
			int tm = (tl + tr) / 2 ;
			if(pos <= tm) // left jao
				update_util(2*v, tl, tm, pos, new_val) ;
			else 
				update_util(2*v + 1, tm+1, tr, pos, new_val) ;
			t[v] = set_max(t[2*v] , t[2*v + 1]);
		}
	}
	
	void update(int pos , int val){
		 update_util(1,0,n-1,pos,val) ;
	}

} ;


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , q  ;
		cin >> n >> q ;
		Segtree seg(n) ;
		vector<st> a(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i].qual ;
			a[i].id = i ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> a[i].val ;
		}
		seg.build(a,n) ;
		while(q--){
			int tp ; cin >> tp ;
			if(tp == 1){
				int l , r , qt ;
				cin >> l >> r >> qt;
				l-- , r-- ;
				auto s = seg.query(l,r) ;
				seg.update(s.id , qt) ;
			} else {
				int v , i , qt , thr ;
				cin >> v >> i >> qt >> thr ;
				int l = max(0LL , i - 1 - v) , r = min(n - 1 , i - 1 + v) ;
				auto s = seg.query(l , r) ;
				if(s.val < qt || s.qual < thr ){
					cout << "No purchase\n" ;
					continue ;
				} else {
					seg.update(s.id , -qt) ;
					cout << s.id + 1 << '\n' ;
				}
			}
		}
	}
	return 0 ;
}



