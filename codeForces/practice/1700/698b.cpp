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
	int n ;
	cin >> n ;
	DSU dsu(n + 1) ;
	int a[n + 1] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i + 1] ;
	vector<int> v ;
	int start = -1 ;
	for(int i = 1 ; i <= n ; i++){
		if(dsu.merge(i , a[i])){
			v.push_back(i) ;
			if(i == a[i]) start = v.size() - 1 ;
		}
	}
	int ans = v.size() ;
	if(~start) {
		ans-- ;
		swap(v[start] , v[0]) ;
	}
	for(int i = 0 ; i < v.size() ; i++){
		a[v[i]] = v[0] ; 
	}
	cout << ans << '\n' ;
	for(int i = 1 ; i <= n ; i++) cout << a[i] << " " ;
	return 0 ;
}


