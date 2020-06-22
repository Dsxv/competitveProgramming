#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
vector<int> visited ;

struct prov{
	int a , b , id ;
} ;

void dfs(int start , vector<pair<int,int>> &a , vector<int>& tp){
	if(visited[start]) return ;
	tp.push_back(start) ;
	visited[start] = 1 ;
	for(auto i : g[start]){
		if(a[i] == a[start]){
			dfs(i,a,tp) ;
		}
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		g.clear() ;
		g.resize(n) ;
		visited.clear() ;
		visited.resize(n) ;
		vector<prov> v(n) ;
		vector<pair<int,int>> a(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> v[i].a ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> v[i].b ;
			int gc = __gcd(v[i].a , v[i].b) ;
			if(gc) v[i].a /= gc ; v[i].b /= gc ;
			a[i] = make_pair(v[i].a , v[i].b) ;
			v[i].id = i ;
		}
		for(int i = 0 ; i < m ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		sort(v.begin() , v.end() , [&](prov x , prov y){
				return (x.a*y.b) > (x.b*y.a) ;
				}) ;
		pair<int,int> p(v[0].a , v[0].b) ;
		vector<vector<int>> comp ;
		for(int i = 0 ; i < n ; i++){
			if(p.first != v[i].a || p.second != v[i].b) continue  ;
			if(!visited[v[i].id]){
				vector<int> tp ;
				dfs(v[i].id , a , tp) ;
				comp.push_back(tp) ;
			}
		}
		int mx = 0 ;
		for(int i = 0 ; i < comp.size() ; i++){
			if(comp[mx].size() < comp[i].size()){
				mx = i ;
			}
		}
		cout << (int)comp[mx].size() << '\n' ;
		for(auto i : comp[mx]) cout << i + 1 << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

