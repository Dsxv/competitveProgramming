#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct queries{
	int l , r , ans ;
	queries(){
		l = r = ans = 0 ;
	}
} ;
const int N = 1e5 + 10 ;

int a[N] ;

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
			t[v] = t[2*v] + t[2*v+1] ;
		}
	}
	
	void build(int * a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	int query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return 0 ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return (query_util(2*v, tl, tm, l, min(r,tm)) 
			+ query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
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
			t[v] = (t[2*v] + t[2*v + 1]);
		}
	}
	
	void update(int pos , int val){
		 update_util(1,0,n-1,pos,val) ;
	}

} seg(N);

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ; 
	cin >> n >> m ;
	seg.build(a,n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	vector<int> v[n] ;
	queries q[m] ;
	for(int i = 0 ; i < m ; i++){
		cin >> q[i].l >> q[i].r ;
		q[i].l-- , q[i].r-- ;
		v[q[i].r].push_back(i) ;
	}
	map<int,vector<int>> mp ;
	for(int i = 0 ; i < n ; i++){
		mp[a[i]].push_back(i) ;
		int sz = mp[a[i]].size() ;
		if(sz == a[i]){
			seg.update(mp[a[i]][0],1) ;
		} else if(sz == a[i] + 1){
			seg.update(mp[a[i]][1] , 1) ;
			seg.update(mp[a[i]][0] , -1) ;
		} else if(sz >= a[i] + 2){
			seg.update(mp[a[i]][sz-a[i]] , 1) ;
			seg.update(mp[a[i]][sz-a[i]-1],-1) ;
			seg.update(mp[a[i]][sz-a[i]-2],0) ;
		}
		for(auto j : v[i]){
			q[j].ans = seg.query(q[j].l , i) ;
		}
	}
	for(int i = 0 ; i < m ; i++){
		cout << q[i].ans << '\n' ;
	}
	return 0 ;
}

