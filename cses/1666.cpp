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
		return true ;
	}
} ;


int32_t main(){
	int n , m ;
	cin >> n >> m ;
	DSU dsu(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		dsu.merge(f,s) ;
	}
	set<int> parent ;
	for(int i = 0 ; i < n ; i++){
		parent.insert(dsu.gp(i)) ;
	}
	int x = *parent.begin() ;
	parent.erase(parent.begin()) ;
	cout << parent.size() << '\n' ;
	for(int i : parent){
		cout << x + 1<< " " << i + 1 << '\n' ;
	}
	return 0 ;
}


