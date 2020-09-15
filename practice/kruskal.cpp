#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct edge{
	int f , s , w ;
} ;

struct DSU{
	vector<int> val , parent ;
	DSU(){
	}
	DSU(int n){
		val.resize(n) ;
		parent.resize(n) ;
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}

	int gp(int x){
		if(parent[x] == x) return x ;
		return parent[x] = gp(parent[x]) ;
	}

	bool merge(int f , int s ){
		f = gp(f) , s = gp(s) ;
		if(f == s) return false ;
		if(val[f] < val[s]) swap(f , s) ;
		val[f] += val[s] ;
		parent[s] = f ;
		return true ;
	}
} ;



int32_t main(){
	int n , m; 
	cin >> n >> m;
	DSU dsu(n) ;
	edge e[m] ;
	for(int i = 0 ; i < m ; i++){
		int f , s , w ;
		cin >> f >> s >> w ;
		f-- , s-- ;
		e[i].f = f , e[i].s = s , e[i].w = w ;
	}
	sort(e , e + m , [&](edge a , edge b){
			return a.w < b.w ; }) ;
	vector<edge> tree ;
	int cur = 0 ;
	while(tree.size() < n - 1){
		if(dsu.merge(e[cur].f , e[cur].s)){
			tree.push_back(e[cur]) ;
		}
		cur++ ;
	}
	for(auto i : tree){
		cout << i.f + 1 << " " << i.s + 1 << " " << i.w << '\n' ;
	}
	return 0 ;
}

