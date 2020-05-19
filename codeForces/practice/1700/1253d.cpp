#include <bits/stdc++.h>
using namespace std ;

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
		if(a == b) return false ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return true ;
	}
} ;
const int N = 2e5 ;
vector<int> v[N] ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	DSU dsu(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		v[f].push_back(s) ;
		v[s].push_back(f) ;
		dsu.merge(f,s) ;
	}
	map<int,int> mpt , mp ;
	for(int i = 0 ; i < n ; i++){
		mpt[dsu.gp(i)] = i ;
	}
	for(int i = 0 ; i < n ; i++){
		mp[i] = mpt[dsu.gp(i)] ;
	}
	int x = -1 ;
	int ans = 0 ;
	for(int i = 0 ; i < n - 1 ; i = x + 1){
		x = mp[dsu.gp(i)] ;
		for(int j = i + 1 ; j <= x ; j++){
			ans += dsu.merge(i,j) ;
			x = max(x,mp[j]) ;
		}
	}
	cout << ans ;
	return 0 ;
}


