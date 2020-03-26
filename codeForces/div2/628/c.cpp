#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;

vector<int> G[N] ;
vector<int> ans ;
map<pair<int,int>,int> mp ;

void dfs(int start , int parent = -1){
	if((int)G[start].size() == 1){
		int x = mp[{G[start][0],start}] ;
		ans.push_back(x) ;
	}
	for(auto i : G[start]){
		if(i != parent){
			dfs(i,start) ;
		}
	}
}

int32_t main(){
	ans.clear() ;
	mp.clear() ;
	int n; 
	cin >> n ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		mp[{f,s}] = i ;
		mp[{s,f}] = i ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	if(n == 2){
		cout << 0 ;
		return 0 ;
	}
	dfs(0) ;
	int count = 0 ;
	int val[n-1] ;
	for(int i = 0 ; i < n - 1 ; i++) val[i] = -1 ;
	for(auto i : ans) val[i] = count++ ;
	for(int i = 0 ; i < n - 1 ; i++){
		if(val[i] != -1) cout << val[i] << '\n' ;
		else cout << count++ << '\n' ;
	}
	return 0 ;
}

