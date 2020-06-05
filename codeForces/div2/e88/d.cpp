#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

const int N = 1e5 + 10 ;

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
		t.assign(4*n , 0) ;
	}
	// v is current vertex in segtree , tl , tr in array
	void build_util(int* a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = a[tl] ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = max(t[2*v] , t[2*v+1]) ;
		}
	}
	
	void build(int * a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	int query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return INT_MIN ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return max(query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
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
			t[v] = max(t[2*v] , t[2*v + 1]);
		}
	}
	
	void update(int pos , int val){
		 update_util(1,0,n-1,pos,val) ;
	}

} sp(N) , sf(N) ;

pair<int,int> p[N] ;

void solve(int * a , int n){
	stack<int> s ;
	for(int i = 1 ; i <= n ; i++){
		while(s.size() && a[i] > a[s.top()]){
			p[s.top()].first = i - 1;
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].first = n ;
		s.pop() ;
	}
	for(int i = n ; i >= 1 ; i--){
		while(s.size() && a[i] > a[s.top()]){
			p[s.top()].second = i + 1 ;
			s.pop() ;
		}
		s.push(i) ;
	}
	while(s.size()){
		p[s.top()].second = 1 ;
		s.pop() ;
	}
}


int32_t main(){
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	int n ;
	cin >> n ;
	int a[n+2] = {} ;
	int pre[n+2] = {} , suf[n+2] = {} ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int i = 1 ; i <= n ; i++){
		pre[i] = a[i] + pre[i-1] ;
	}
	for(int i = n ; i >= 1 ; i--){
		suf[i] = a[i] + suf[i+1] ;
	}
	solve(a,n) ;
	sp.build(pre,n+2) ;
	sf.build(suf,n+2) ;
	int ans = 0 ;
	for(int i = 1;  i <= n ; i++){
		int a = sf.query(p[i].second , i) - suf[i] ;
		int b = sp.query(i , p[i].first) - pre[i] ;
		ans = max(ans, a+b) ;
	}
	cout << ans ;
	return 0 ;
}



