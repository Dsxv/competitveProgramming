#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;	

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n , m , k ;
		cin >> n >> m >> k ;
		g.clear() ;
		g.resize(n) ;
		for(int i = 0 ; i < m ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		vector<int> dis(n , -1) , visited(n) ;

		queue<pair<int,int>> q ;
		for(int i = 0 ; i < k ; i++){
			int x ; cin >> x ;
			x-- ;
			q.push({x , 0}) ;
			visited[x] = 1 ;
		}
		while(q.size()){
			int cur = q.front().first , d = q.front().second ;
			q.pop() ;
			dis[cur] = d ;
			for(auto i : g[cur]){
				if(visited[i]) continue ;
				visited[i] = 1 ;
				q.push({i , d + 1}) ;
			}
		}
		cin >> m ;
		while(m--){
			int x ; cin >> x ;
			x-- ;
			cout << dis[x] << '\n' ;
		}
	}
	return 0 ;
}

