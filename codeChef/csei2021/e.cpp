#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> visited ;
vector<vector<int>> g ;

void dfs2(int start , vector<int>&mxd , int d = 0){
	visited[start] = 1 ;
	mxd[start] = d ;
	for(auto i : g[start]){
		if(!visited[i]){
			dfs2(i , mxd, d + 1) ;
		}
	}
}

pair<int,int> diameter(int start , int n){
	vector<int> mxd(n) ;
	visited.clear() ;
	visited.resize(n) ;
	dfs2(start,mxd) ;
	int mx = *max_element(mxd.begin() , mxd.end()) ;
	for(int i = 0 ; i < n ; i++){
		if(mxd[i] == mx) return {i , mx} ;
	}
}

int32_t main(){
	// start is node with degree 1
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		g.clear() ; visited.clear() ;
		g.resize(n) ; visited.resize(n) ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		pair<int,int> x = diameter(0 , n) ;
		pair<int,int> ans = diameter(x.first , n) ;
		cout << (ans.second + 1) / 2 << '\n' ;
	}
	return 0 ;
}


