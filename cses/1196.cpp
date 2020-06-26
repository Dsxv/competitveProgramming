#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int INF = 1e18 ;
vector<vector<pair<int,int>>> g ;
int k ;
void dijkstra(int start , int n){
	using pii = pair<int,int> ;
	priority_queue<pii , vector<pii> , greater<pii>> pq ;
	pq.push({0,start}) ;
	multiset<int> ms[n] ;
	while(pq.size()){
		auto [val,cur] = pq.top() ;
		pq.pop() ;
		if(ms[cur].size() >= k){
			if(cur == n-1) break ;
			continue ;
		} else {
			ms[cur].insert(val) ;
		}
		for(auto [to,dis] : g[cur]){
			if(ms[to].size() < k){
				pq.push({val + dis , to}) ;
			}
		}
	}
	for(auto i : ms[n-1]){
		cout << i << " ";
	}
	
}

int32_t main(){
	int n , m ;
	cin >> n >> m >> k ;
	g.resize(n) ;
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
	}
	int start = 0 ;
	dijkstra(start,n) ; // 0 is source vertex
	// ans is all path from source , parent is for retracing path from any vertex to source
	return 0 ;
}


