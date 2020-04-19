#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ; // change this according to n

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

vector<int> G[N] ;

int32_t main(){
	int n , m ; 
	cin >> n >> m ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i].first ;
		a[i].second = i ;
	}
	sort(a,a+n,greater<pair<int,int>>()) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	bool visited[n] = {};
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int id = a[i].second ;
		visited[id] = 1 ;
		int cnt = 0 ;
		int sum = 0 ;
		for(auto j : G[id]){
			if(visited[j] && (dsu.gp(j) != dsu.gp(id))){
				int x = dsu.val[dsu.gp(j)] , y = dsu.val[dsu.gp(id)] ;
				ans += x*y*a[i].first ;
				dsu.merge(id,j) ;
			}
		}
	}
	ans *= 2 ;
	double fans = (double)ans/(n*(n-1)) ;
	cout << fixed << setprecision(10) << fans ;
	return 0 ;
}


