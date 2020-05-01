#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 110 ; // change this according to n

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
		return false ;
	}
} dsu ;

vector<int> G[N] ;

int32_t main(){
	int n , m; 
	cin >> n >> m ;
	int count = 0 ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		count += dsu.merge(f,s);
	}
	if(count == 1 && n == m){
		cout << "FHTAGN!" ;
	} else {
		cout << "NO" ;
	}
	return 0 ;
}


