#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
vector<int> G[N] ;

bool dfs(int* a , int start , int col , int parent){
	if(a[start] != col){
		return false ;
	}
	for(auto i : G[start]){
		if(i == parent) continue ;
		if(!dfs(a,i,col,start)) return false ;
	}
	return true ;
}

bool solve(int* a , int start){
	bool ans = true ;
	for(auto i : G[start]){
		ans &= dfs(a,i,a[i],start) ;
	}
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	vector<pair<int,int>> edges ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
		edges.push_back({f,s}) ;
	}
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	bool ok = true ;
	int ans = 0 ;
	//cout << solve(a,1) << endl ;
	for(auto i : edges){
		int x = i.first , y = i.second ;
		if(a[x] != a[y]){
			if(solve(a,x)){
				ans = x ;
			} else if(solve(a,y)){
				ans = y ;
			} else {
				ok = false ;
			}
			break ;
		}
	}
	if(!ok){
		cout << "NO" ;
	} else {
		cout << "YES\n" << ans + 1 ;
	}
	return 0 ;
}

