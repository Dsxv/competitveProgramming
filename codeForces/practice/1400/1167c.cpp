#include <bits/stdc++.h>
using namespace std ;

#define int long long


struct DSU{
	vector<int> parent , val ;
	int N ;
	DSU(){
		N = 10 ;
	}
	DSU(int n){
		N = n ;
		parent.resize(n) ;
		val.resize(n) ;
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return false ;
	}
} ;


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	DSU dsu(n) ;
	while(m--){
		int t ;
		cin >> t ; 
		if(!t) continue ;
		t-- ;
		int x ; cin >> x ;
		while(t--){
			int y ; cin >> y ;
			dsu.merge(x-1 , y-1) ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout << dsu.val[dsu.gp(i)] << ' ' ;
	}
	return 0 ;
}


