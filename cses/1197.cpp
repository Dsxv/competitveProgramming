#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e15 ;
struct edge{
	int a , b , c ;
} ;
vector<edge> g ;

void solve(int start , int n){
	vector<int> d(n,INF) ;
	vector<int> p(n,-1) ;
	p[start] = start ;
	d[start] = 0 ;
	int x ;
	for(int i = 0 ; i < n ; i++){
		x = -1 ;
		for(auto j : g){
			if(d[j.b] > d[j.a] + j.c){
				d[j.b] = max(-INF , d[j.a] + j.c) ;
				p[j.b] = j.a ;
				x = j.b ;
			}
		}
	}
	// x != -1 means last run me bhi kuch update hua hai , gadbad
	if(~x){
		for(int i = 0 ; i < n ; i++){
			x = p[x] ;
		}
		// now we are certain it's in -ve cycle 
		int cur = p[x] ;
		vector<int> v ;
		v.push_back(x) ;
		while(cur != x){
			v.push_back(cur) ;
			cur = p[cur] ;
		}
		v.push_back(cur) ;
		reverse(v.begin() , v.end()) ;
		cout << "YES\n" ;
		for(auto i : v) cout << i + 1 << " " ;
		exit(0) ;
	} else {
		return  ;
	}
}

int32_t main(){
	int n , m  ;
	cin >> n >> m ;
	g.resize(m) ;
	for(int i = 0 ; i < m ; i++){
		cin >> g[i].a >> g[i].b >> g[i].c ;
		g[i].a-- , g[i].b-- ;
	}
	solve(0,n) ;
	cout << "NO" ;
	return 0 ;
}


