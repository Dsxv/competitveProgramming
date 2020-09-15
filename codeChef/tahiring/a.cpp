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
	int x[m] ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		x[i] = f - 1 ;
		dsu.merge(f-1,s-1) ;
	}
	map<int,int> mp ;
	for(int i = 0 ; i < m ; i++){
		mp[dsu.gp(x[i])]++ ;
	}
	int ans = 0 ;
	for(auto i : mp){
		ans += i.second - dsu.val[i.first] + 1 ;
	}
	cout << ans ;
	return 0 ;
}


