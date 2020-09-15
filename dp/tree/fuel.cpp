#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<pair<int,int>>> g ;
vector<int> a ;
const int N = 1e5 + 10 ;
int cnt[N] ;
int ans = 0 ;

void solve(int start , int parent = -1){
	cnt[start] = a[start] ;
	ans = max(ans , a[start]) ;
	priority_queue< int , vector<int> , greater<int> > pq ;
	for(auto i : g[start]){
		if(i.first == parent) continue ;
		solve(i.first , start) ;
		pq.push(max(0LL , cnt[i.first] - i.second)) ;
		if(pq.size() > 2) pq.pop() ;
	}
	if(pq.size() == 0) return ;
	if(pq.size() >= 2){
		int x = pq.top() ; pq.pop() ;
		int y = pq.top() ; pq.pop() ;
		ans = max(ans , x + y + a[start]) ;
		cnt[start] = a[start] + y ;
	} else {
		int x = pq.top() ; pq.pop() ;
		ans = max(ans , x + a[start]) ;
		cnt[start] = a[start] + x ;
	}
}

int32_t main(){
	int n; 
	cin >> n ;
	a.resize(n) ;
	g.resize(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s , c;
		cin >> f >> s >> c ;
		f-- , s-- ;
		g[f].push_back({s,c}) ;
		g[s].push_back({f,c}) ;
	}
	solve(0) ;
	cout << ans ;
	return 0 ;
}

