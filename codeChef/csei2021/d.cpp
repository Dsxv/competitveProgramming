#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

const int N = 1e5 + 10 ;

struct Segtree{
	vector<pair<int,int>> t ;
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
	void build_util(vector<pair<int,int>>& a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = a[tl] ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = min(t[2*v] , t[2*v+1]) ;
		}
	}
	
	void build(vector<pair<int,int>> & a){
		n = a.size() ;
		build_util(a,1,0,n-1) ;
	}

	pair<int,int> query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return {INT_MAX,INT_MAX} ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return min(query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	pair<int,int> query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}
} ;

vector<vector<pair<int,int>>> g ;
vector<pair<int,int>> euler ;
vector<int> fo ;
vector<int> pre ;

void dfs(int start , int d = 0 , int p = -1){
	fo[start] = euler.size() ;
	euler.push_back({d,start}) ;
	for(auto i : g[start]){
		if(i.first == p) continue ;
		dfs(i.first , d+1 , start) ;
		euler.push_back({d,start}) ;
	}
}

void solve(int start , int d = 0 , int parent = -1){
	pre[start] = d ;
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		solve(i.first , d + i.second , start) ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , q , r ;
		cin >> n >> q >> r ;
		r-- ;
		g.clear() ; fo.clear() ; euler.clear() ;
		g.resize(n) ; fo.resize(n) ;
		
		pre.clear() ; pre.resize(n) ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s , w;
			cin >> f >> s >> w ;
			f-- , s-- ;
			g[f].push_back({s , w}) ;
			g[s].push_back({f , w}) ;
		}
		dfs(r) ;
		solve(r) ;
		Segtree seg(2*n) ;
		seg.build(euler) ;
		
		while(q--){
			int l , r ;
			cin >> l >> r ;
			int L , R ; 
			L = --l , R = --r ;
			l = fo[l] ;
			r = fo[r] ;
			if(l > r) swap(l, r) ;
			int lca = seg.query(l , r).second ;
			cout << pre[L] + pre[R] - 2*pre[lca] << '\n' ;
		}
	}
	return 0 ;
}

