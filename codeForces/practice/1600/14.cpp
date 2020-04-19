#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 500 ;
vector<int> g[N] , h[N] ;

int bfs(vector<int>* g , int start , int n){
	queue<pair<int,int>> q ;
	q.push({start,0}) ;
	int a[n] = {} ;
	a[start] = 1 ;
	while(q.size()){
		start = q.front().first ;
		int d = q.front().second ;
		if(start == (n-1)) return d ;
		q.pop() ;
		for(auto i : g[start]){
			if(!a[i]){
				a[i] = 1 ;
				q.push({i,d+1}) ;
			}
		}
	}
	return -1 ;
}

int32_t main(){
	int n , m; 
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	for(int i = 0 ; i < n ; i++){
		set<int> s ;
		for(int j = 0 ; j < n ; j++) {
			if(j != i) 
				s.insert(j) ;
		}
		for(auto j : g[i]) s.erase(j) ;
		h[i] = vector<int>(s.begin(),s.end()) ;
	}
	int x1 = bfs(g,0,n) ;
	int x2 = bfs(h,0,n) ;
	if(x1 == -1 || x2 == -1){
		cout << -1 ;
		return 0 ;
	}
	cout << max(x1 , x2) ;
	return 0 ;
}

