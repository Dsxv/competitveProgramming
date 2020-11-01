#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<vector<int>> g; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, vector<pair<int,int>>&pr , int p = -1 ) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, pr , v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
              pr.push_back({min(to , v) + 1 , max(to , v) + 1}) ;
			}
        }
    }
}

vector<pair<int,int>> find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
	vector<pair<int,int>> pr ;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i , pr);
    }
	return pr ;
}

vector<pair<int , int>> criticalConnections(int n , int m , vector<pair<int,int>> roads){
	g.clear() ;
	visited.clear() ;
	low.clear() ;
	g.resize(n) ;
	for(auto i : roads){
		g[i.first-1].push_back(i.second-1) ;
		g[i.second-1].push_back(i.first-1) ;
	}
	return find_bridges(n) ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
	int n , m ;
	cin >> n >> m ;
	vector<pair<int,int>> v ;
	v.resize(m) ;
	for(int i = 0 ; i < m ; i++){
		cin >> v[i].first >> v[i].second ;
	}
	auto ans = criticalConnections(n , m , v) ;
	for(auto i : ans) cout << i.first << " " << i.second << '\n' ; 
	cout << endl ;
	}
	return 0 ;
}


