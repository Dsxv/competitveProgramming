#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e15 ;
vector<vector<pair<int,int>>> g ;

vector<int> dijkstra(int start , int n){
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
	vector<int> ans(n , INF) ;
	ans[start] = 0 ;
	pq.push({0,start}) ;
	vector<int> visited(n) ;
	while(pq.size()){
		auto [dis , cur] = pq.top() ;
		visited[cur] = true ;
		pq.pop() ;
		for(auto [node , weight] : g[cur]){
			if(visited[node]) continue ;
			if(ans[node] > (dis + weight)){
				ans[node] = dis + weight ;
				pq.push({ans[node] , node}) ;
			}
		}
	}
	return ans; 
}


int32_t main(){
	int n , m;
	cin >> n >> m;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , w ;
		cin >> f >> s >> w ;
		f-- , s-- ;
		g[f].push_back({s,w}) ;
		g[s].push_back({f,w}) ;
	}
	int start ;
	cin >> start ;
	start-- ;
	vector<int> ans = dijkstra(start , n) ;
	for(int i = 0 ; i < n ; i++) cout << i+1 << " " << ans[i] << "\n" ;
	return 0 ;
}

