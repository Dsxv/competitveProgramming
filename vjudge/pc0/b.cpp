#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
map<int,int> mp[N] ;
vector<pair<int,int>> g[N] ;
const int INF = 1e15 ;

pair<vector<int>,vector<int>> dijkstra(int start , int n){
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
	for(int i = 0 ; i < m ; i++){
		int f , s , w;
		cin >> f >> s >> w ;
		f-- , s-- ;
		if(mp[f].count(s)){
			mp[f][s] = min(mp[f][s] , w) ;
			mp[s][f] = min(mp[s][f] , w) ;
		} else {
			mp[f][s] = mp[s][f] = w ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(auto j : mp[i]){
			g[i].push_back({j.first , j.second}) ;
		}
	}
	auto [ans , p] = dijkstra(0 , n) ;
	if(ans[n-1] >= INF){
		cout << -1 ;
		return 0 ;
	}
	int cur = n - 1 ;
	vector<int> v ;
	while(cur){
		v.push_back(cur) ;
		cur = p[cur] ;
	}
	v.push_back(0) ;
	reverse(v.begin() , v.end()) ;
	for(auto i : v) cout << i+1 << " " ;
	return 0 ;
}

