#include <bits/stdc++.h>
using namespace std ;

#define int long long
vector<int> child ;
vector<vector<pair<int,int>>> g ;
vector<pair<int,int>> edge ;

int dfs(int start , int parent = -1){
	if(g[start].size() == 1){
		child[start] = 1 ;
	}
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		child[start] += dfs(i.first , start) ;
		edge.push_back({i.second , child[i.first]}) ;
	}
	return child[start] ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , sum; 
		cin >> n >> sum ;
		g.clear() ;
		g.resize(n) ;
		child.clear() ;
		child.resize(n) ;
		edge.clear() ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s , w;
			cin >> f >> s >> w ;
			f-- , s-- ;
			g[f].push_back({s,w}) ;
			g[s].push_back({f,w}) ;
		}
		dfs(0) ; //store child count
		int ans = 0 ;
		priority_queue<pair<int,int>> pq ;
		for(int i = 0 ; i < edge.size() ; i++){
			ans += edge[i].first*edge[i].second ;
			pq.push({(edge[i].first - edge[i].first/2)*edge[i].second , i}) ;
		}
		int cnt = 0 ;
		while(ans > sum){
			cnt++ ;
			auto [dif , i] = pq.top() ;
			pq.pop() ;
			ans -= dif ;
			edge[i].first /= 2 ;
			pq.push({(edge[i].first - edge[i].first/2)*edge[i].second , i}) ;
		}
		cout << cnt << '\n' ;
	}
	return 0 ;
}

