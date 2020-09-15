#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<vector<int>> g; // adjacency list of graph
vector<vector<pair<int,int>>> vg ;
vector<bool> visited;
vector<int> tin, low;
const int N = 3e5 + 10 ;
map<int,int> mp[N] ;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                mp[v][to] = 1 ;
				mp[to][v] = 1 ;
			}
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void dfs2(int start , vector<int>&mxd , int d = 0){
	visited[start] = 1 ;
	mxd[start] = d ;
	for(auto i : vg[start]){
		if(!visited[i.first]){
			dfs2(i.first, mxd, d + i.second) ;
		}
	}
}

pair<int,int> diameter(int start , int n){
	vector<int> mxd(n) ;
	visited.clear() ;
	visited.resize(n) ;
	dfs2(start,mxd) ;
	int mx = *max_element(mxd.begin() , mxd.end()) ;
	for(int i = 0 ; i < n ; i++){
		if(mxd[i] == mx) return {i , mx} ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	g.resize(n) ;
	vg.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	find_bridges(n) ;
	int start = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(auto j : g[i]){
			bool x = mp[i].count(j) ;
			vg[i].push_back({j,x}) ;
		}
		if(vg[i].size() == 1) start = i ;
	}
	auto node = diameter(start,n) ;
	auto ans = diameter(node.first , n) ;
	cout << ans.second ;
	return 0 ;
}


