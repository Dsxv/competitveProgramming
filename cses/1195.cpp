#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e18 ;

pair<vector<int>,vector<int>> dijkstra(vector<vector<pair<int,int>>>& g , int start , int n){
	vector<int> d(n,INF) ;
	vector<int> p(n,-1) ;
	using pii = pair<int,int> ;
	d[start] = 0 ;
	p[start] = start ;
	priority_queue<pii , vector<pii> , greater<pii>> pq ;
	pq.push({0,start}) ;
	while(pq.size()){
		auto [val,cur] = pq.top() ;
		pq.pop() ;
		if(d[cur] != val) continue ; // koi aur accha change kargya hai isse

		for(auto [to,dis] : g[cur]){
			if(d[to] > d[cur] + dis) {
				pq.push({d[cur] + dis , to}) ;
				d[to] = d[cur] + dis ;
				p[to] = cur ;
			}
		}
	}
	return {d,p} ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	vector<vector<pair<int,int>>> g , g_comp;
	g.resize(n) ;
	g_comp.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
		g_comp[s].push_back({f,c}) ;
	}
	auto [dp1,p] = dijkstra(g,0,n) ; // 0 is source vertex
	auto [dp2,p2] = dijkstra(g_comp,n-1,n) ;
	int ans = INF ;
	for(int i = 0 ; i < n ; i++){
		for(auto j : g[i]){
			ans = min(dp1[i] + dp2[j.first] + j.second/2 , ans) ;
		}
	}
	cout << ans ;
	return 0 ;
}


