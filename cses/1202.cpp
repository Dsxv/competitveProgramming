#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e18 ;
const int mod = 1e9 + 7 ;

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
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	vector<vector<pair<int,int>>> gg , gcomp , g;
	g.resize(n) ; gg.resize(n) ; gcomp.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		gg[f].push_back({s,c}) ;
		gcomp[s].push_back({f,c}) ;
	}
	int start = 0 ;
	auto [dp1,p1] = dijkstra(gg,start,n) ; // 0 is source vertex
	// ans is all path from source , parent is for retracing path from any vertex to source
	auto [dp2,p2] = dijkstra(gcomp , n-1,n) ;
	for(int i = 0 ; i < n ; i++){
		for(auto j : gg[i]){
			if(dp1[i] + j.second + dp2[j.first] == (dp1[n-1])){
				g[i].push_back({j.first,1}) ;
			}
		}
	}
	cout << dp1.back() << " " ;
	vector<int> dp(n,-1)  ;
	dp[n-1] = 1 ;
	function<int(int)> dfs = [&](int start) -> int {
		if(start == n-1){
			return 1 ;
		}
		if(~dp[start]) return dp[start] ;
		int cnt = 0 ;
		for(auto i : g[start]) {
			cnt = (cnt + dfs(i.first)) % mod ;
		}
		return dp[start] = cnt ;
	} ; 
	int ans1 = dfs(0) ;
	cout << ans1 << " "  ;
	auto [dp3 , p3] = dijkstra(g,0,n) ;
	cout << dp3.back() <<  " "  ;
	for(int i = 0 ; i < n ; i++){
		for(auto &j : g[i]) j.second *= -1 ;
	}
	auto [dp4 , p4] = dijkstra(g,0,n) ;
	cout << dp4.back()*-1 ;
	return 0 ;
}


