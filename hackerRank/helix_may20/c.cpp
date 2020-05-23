#include <bits/stdc++.h>
using namespace std ;

#define int long long


struct DSU{
	vector<int> parent , val ;
	int N ;
	int comp ;
	DSU(){
		N = 10 ;
	}
	DSU(int n){
		N = n ;
		comp = n ;
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
		comp-- ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return true ;
	}
} ;


int32_t main(){
	int n , q ;
	cin >> n >> q ;
	DSU dsu(n) ;
	while(q--){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		dsu.merge(f,s) ;
		cout << dsu.comp << '\n' ;
	}
	return 0 ;
}


