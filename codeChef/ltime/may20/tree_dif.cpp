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

vector<int> pp ;
vector<vector<int>> G ;
vector<pair<int,int>> euler ;
vector<int> fo ;
vector<int> a;

void dfs(int start = 0 , int d = 0 , int parent = -1){
	fo[start] = euler.size() ;
	euler.push_back({d,start}) ;
	if(parent != -1) pp[start] = parent ;
	else pp[start] = start ;
	for(auto i : G[start]){
		if(i == parent) continue ;
		dfs(i,d+1,start) ;
		euler.push_back({d,start}) ;
	}
}

int32_t main(){
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , q ; 
		cin >> n >> q ;
		G.clear() ; fo.clear() ; euler.clear() ; pp.clear() ; a.clear() ;
		G.resize(n) ; fo.resize(n) ; pp.resize(n) ; a.resize(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			G[f].push_back(s) ;
			G[s].push_back(f) ;
		}
		dfs() ;
		Segtree s(2*n) ;
		s.build(euler) ;
		while(q--){
			int l , r ;
			cin >> l >> r ;
			l-- , r-- ;
			if(fo[l] > fo[r]) swap(l,r) ;
			pair<int,int> lca = s.query(fo[l],fo[r]) ;
			int hl = euler[fo[l]].first ;
			int hr = euler[fo[r]].first ;
			if(hl+hr-2*lca.first > 100){
				cout << 0 << '\n' ;
				continue ;
			}
			int temp[101] = {} ;
			int cur = l ;
			while(cur != lca.second){
				temp[a[cur]]++ ;
				cur = pp[cur] ;
			}
			cur = r ;
			while(cur != lca.second){
				temp[a[cur]]++ ;
				cur = pp[cur] ;
			}
			temp[a[lca.second]]++ ;
			int minval = 100 ;
			int prev = INT_MIN ;
			for(int i = 1 ; i < 101 ; i++) {
				if(temp[i] > 1) minval = 0 ;
				if(temp[i]) minval = min(minval , i - prev) ;
				if(temp[i]) prev = i ; 
			}
			cout << minval << '\n' ;
		}
	}
	return 0 ;
}

