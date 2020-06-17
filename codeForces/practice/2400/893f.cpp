#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  

const int N = 5e5 + 10 ;

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
	pair<int,int> set_max( pair<int,int> a , pair<int,int> b){
		if(a.first > b.first) return a ;
		else return b ;
	}
	// first element is max val , second element is index
	void build_util(int* a , int v , int tl , int tr){
		if(tl == tr){
			t[v] = {a[tl] , tl} ;
		}else{
			int tm = (tl+tr)/2 ;
			build_util(a, 2*v, tl, tm) ; build_util(a, 2*v+1, tm+1, tr) ;
			t[v] = set_max(t[2*v] , t[2*v + 1]) ;
		}
	}
	
	void build(int * a , int l){
		n = l ;
		build_util(a,1,0,n-1) ;
	}

	pair<int,int> query_util(int v , int tl , int tr , int l , int r){
		if(l > r){
			return {0,0} ;
		}
		if(tl == l && tr == r){
			return t[v] ;
		}
		int tm = (tl + tr) / 2 ;
		return set_max(query_util(2*v, tl, tm, l, min(r,tm)) 
			, query_util(2*v + 1, tm + 1, tr, max(l,tm+1), r)) ;
	}

	pair<int,int> query(int l , int r){
		return query_util(1,0,n-1,l,r) ;
	}

	void update_util(int v , int tl , int tr , int pos , pair<int,int> new_val){
		if(tl == tr){
			t[v] = new_val ;
		}else{
			int tm = (tl + tr) / 2 ;
			if(pos <= tm) // left jao
				update_util(2*v, tl, tm, pos, new_val) ;
			else 
				update_util(2*v + 1, tm+1, tr, pos, new_val) ;
			t[v] = set_max(t[2*v] , t[2*v + 1]);
		}
	}
	
	void update(int pos , pair<int,int> val){
		 update_util(1,0,n-1,pos,val) ;
	}

} seg(N);


int32_t main(){
	// seg.build(a,n) ;
	// seg.query(l,r) ;
	// seg.update(pos,val) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int a[n+1] ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	int m ;
	cin >> m ;
	vector<int> v[n+1] ;
	vector<pair<int,int>> q ;
	for(int i = 0 ; i < m ; i++){
		int x , y ; cin >> x >> y ;
		q.push_back({x,y}) ;
		v[y].push_back(i) ;
	}
	map<int,vector<int>> mp;
	int temp[n+1] = {} ;
	seg.build(temp , n+1);
	int N = 1e6 ;
	vector<int> ans(m) ;
	for(int i = 1 ; i <= n ; i++){
		mp[a[i]].push_back(i) ;
		int l = mp[a[i]].size() ;
		if(l >= 2){
			int id = mp[a[i]][l-2] ;
			seg.update(id , {0 , id}) ;
			seg.update(i,{N-id,i}) ;
		} else {
			seg.update(i,{N,i}) ;
		}
		for(auto j : v[i]){
			auto x = seg.query(q[j].first , q[j].second) ;
			if(x.first > N - q[j].first){
				ans[j] = a[x.second] ;
			} else {
				ans[j] = 0 ;
			}
		}
	}
	for(auto i : ans) cout << i << '\n' ;

	return 0 ;
}
