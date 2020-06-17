#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;


struct Segtree{
	vector<vector<int>> t;
	int n ;

	Segtree(){
		n = N ; 
		t.resize(4*n) ;
	}

	Segtree(int n){
		this->n = n ;
		t.resize(4*n) ;
	}

	void build_util(pair<int,int> a[], int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = vector<int>(1, a[tl].second);
		} else {
			int tm = (tl + tr) / 2;
			build_util(a, v*2, tl, tm);
			build_util(a, v*2+1, tm+1, tr);
			merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
				  back_inserter(t[v]));
		}
	}

	void build(pair<int,int> * a , int l){
		n = l ;
		build_util(a , 1 , 0 , n - 1) ;
	}

	int query_util(int v, int tl, int tr, int l, int r, int x) {
		// range l and r are not for segments but for elements
		// so we won't update them , as element at any point can be b/w l and r
		if(tl == tr){
			return t[v][0] ;
		}
		int lc = v*2 , rc = v*2 + 1 ;
		auto f = lower_bound(t[lc].begin() , t[lc].end() , l) ;
		auto s = upper_bound(t[lc].begin() , t[lc].end() , r) ;
		int m = s - f ;
		int tm = (tl + tr) / 2 ;
		if(m >= x){
			return query_util(lc , tl , tm , l , r , x) ;
		} else {
			return query_util(rc , tm + 1 , tr , l , r ,  x - m) ;
		}
	}

	int query(int l , int r , int x){
		return query_util(1,0,n-1,l,r,x) ;
	}
}  ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	Segtree seg(n) ;
	pair<int,int> a[n] ;
	int b[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first ;
		b[i] = a[i].first ;
		a[i].second = i ;
	}
	sort(a,a+n) ;
	seg.build(a,n) ;
	while(m--){
		int l , r , x ;
		cin >> l >> r >> x ;
		cout << b[seg.query(l-1,r-1,x)] << endl ;
	}
}


