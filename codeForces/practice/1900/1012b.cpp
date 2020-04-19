#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 4e5 + 10 ; // change this according to n

struct DSU{
	int parent[N] , val[N] ;
	DSU(){
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
} dsu ;

int32_t main(){
	int n , m , q ;
	cin >> n >> m >>  q ;
	while(q--){
		int r , c;
		cin >> r >> c ;
		r-- , c-- ;
		dsu.merge(r,n+c) ;
	}
	set<int> s;
	for(int i = 0 ; i < n+m ; i++) s.insert(dsu.gp(i)) ;
	cout << (int) s.size() - 1 ;
	return 0 ;
}


