#include <bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;
vector<int> g[N] ;
int a[N] ;

bool check(int x , int y){
	return a[x] < a[y] ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	bool found = true ;
	for(int i = 0 ; i < n ; i++){
		sort(g[i].begin() , g[i].end() , check) ;
		int mn = 1 ;
		for(auto j : g[i]){
			if(a[j] == mn) mn++ ;
		}
		if(mn != a[i]) found = false ;
	}
	if(!found){
		cout << -1 ;
		return 0 ;
	}
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		p[i] = {a[i] , i} ;
	}
	sort(p,p+n) ;
	for(auto i : p) cout << i.second + 1 << " " ;
	return 0 ;
}

