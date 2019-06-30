
#include <bits/stdc++.h>
using namespace std;

#define int long long

void dijkstra(unordered_map<int,int>* edges ,int** dist ,  int start , int n){
		priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
		dist[start][start] = 0 ;
		pq.push({0,start}) ;
		unordered_map<int,int> visited ;
		// cout << "here: ";
		while(pq.size()){
			int u = pq.top().second ; pq.pop() ;
			// cout << u + 1 <<" ";
			visited[u] = 1 ;
			for(auto i : edges[u] ){
				if(!visited.count(i.first)){
					if(dist[start][i.first] > dist[start][u] + i.second){
						dist[start][i.first] = dist[start][u] + i.second ;
						pq.push({dist[start][i.first],i.first}) ;
					}
				}
			}
		}
}

void print(int** dist , int n){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			if(dist[i][j] == INT_MAX) dist[i][j] = -1 ;
			 cout << dist[i][j] << " \n"[j == n-1] ;
		}
}

int32_t main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		// online submission
	#endif	
	int T; 
	cin >> T ;
	for(int t = 1 ; t <= T ; t++) {
		int n , m ;
		cin >> n >> m ;
		unordered_map<int,int> edges[n] ;
		for(int i = 0 ; i < m ; i++){
			int f , s , w ;
			cin >> f >> s >> w;
			f-- , s-- ;
			edges[f][s] = w ;
			edges[s][f] = w ;
		}
		int** dist = new int*[n] ;
		for(int i = 0 ; i < n ; i++){ 
			dist[i] = new int[n] ;
			for(int j = 0 ; j < n ; j++) dist[i][j] = INT_MAX ;
		}
		
		for(int i = 0 ; i < n ; i++){
			dijkstra(edges,dist,i,n) ;
		}
		bool possible = true ;
		for(int i = 0 ; i < n ; i++){
			if(!possible) break ;
			for(auto j : edges[i]){
				// cout << dist[i][j.first] <<" : "<<j.second << '\n';
				if(dist[i][j.first] < j.second){
				 possible = false ; break ;
				}
			}
		}
		// print(dist,n) ;
		printf("Case #%lld: ",t) ;
		if(!possible){
			cout << "Impossible\n" ;
			continue ;
		}
		set<pair<int,int>> s ;
		for(int i = 0 ; i < n ; i++){
	    	for(auto j : edges[i]) s.insert({min(i,j.first),max(i,j.first)}) ;
		}
		cout << s.size() << endl  ;
		for(auto i : s) cout << i.first + 1 <<" " << i.second + 1 << '\n' ;
	}
	return 0;
}


