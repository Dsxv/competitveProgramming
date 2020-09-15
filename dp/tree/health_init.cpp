#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
vector<pair<int,int>> g[N] ;
int ans = 0 ;
int sub[N] ;
void solve(int start , int parent = -1){
	priority_queue<int , vector<int> , greater<int>> pq ;
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		solve( i.first , start ) ;
		pq.push(sub[i.first] + i.second) ;
		if(pq.size() > 2) pq.pop() ;
	}
	if(pq.size() == 0) return ;
	int x = pq.top() ; pq.pop() ;
	ans = max(ans , x) ;
	sub[start] = x ;
	if(pq.size()){
		int y = pq.top() ; pq.pop() ;
		ans = max(ans , x + y) ;
		sub[start] = y ;
	}
}

int32_t main(){
	int n ;
	cin >> n; 
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
		g[s].push_back({f,c}) ;
	}
	solve(0) ;
	cout << ans ;
	return 0 ;
}

