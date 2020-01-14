#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int MAXN = 1e5 + 10 ; // change this according to n

struct DSU{
	int n = MAXN  ;
	int parent[MAXN] , rank[MAXN] ;
	DSU(){
		for(int i = 0 ; i < n ; i++) {
			parent[i] = i ;
			rank[i] = 1 ;
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
		if(rank[a] < rank[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		rank[a] += rank[b] ;
		return true ;
	}
} dsu ;

vector<int> G[MAXN] ;

int32_t main(){
	int n ,  m;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		dsu.merge(f,s) ;
	}
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		mp[dsu.gp(i)]++ ;
	}
	int sum = 0 ;
	for(auto i : mp){
		sum += i.second*(n-i.second) ;
	}
	cout << sum/2 ;
	return 0 ;
}


