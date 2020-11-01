#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
const int N = 1e6 + 10 ;
struct tp{
	int a , b , c ;
	tp() : a(0) , b(0) , c(0) {} 
} ;

struct Segtree{
	vector<tp> t ;
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
	
	tp merge(tp x , tp y){
		tp temp ;
		int val = min(x.b , y.c) ;
		temp.a = x.a + y.a + val ;
		temp.b = x.b + y.b - val ;
		temp.c = x.c + y.c - val ;
		return temp ;
	}

	void build_util(string& a , int v , int tl , int tr){
		if(tl == tr){
			tp temp ;
			if(a[tl] == '(') temp.b++ ;
			else temp.c++ ;
			t[v] = temp ;
		} else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = merge(t[2*v] , t[2*v+1]) ;
		}
	}
	
	void build(string &a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	tp query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			tp temp ;
			return temp ;
		}

		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return merge( query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	tp query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}
} ;


int32_t main(){
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	string s ;
	cin >> s ;
	int n = s.size() ;
	Segtree seg(n) ;
	seg.build(s , n) ;
	int m ;
	cin >> m ;
	while(m--){
		int l , r ;
		cin >> l >> r ;
		l-- , r-- ;
		cout << 2*seg.query(l,r).a << '\n' ;
	}
	return 0 ;
}



