#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
vector<int> G[N] ;
set<int> leaf ;
void dfs(int start , int dis , int parent = -1){
	if(G[start].size() == 1){
		leaf.insert(dis%2) ;
	}
	for(int i: G[start]){
		if(i != parent){
			dfs(i , dis + 1 , start) ;
		}
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	dfs(0,0) ;
	int ans1 = 1 , ans2 = n - 1;
	if(leaf.size() > 1){
		ans1 = 3 ;
	}
	for(int i = 0 ; i < n ; i++){
		int x = 0 ;
		for(int j : G[i]){
			if(G[j].size() == 1){
				x++ ;
			}
		}
		ans2 -= max(0LL, (x-1)) ;
	}
	cout << ans1 << " " << ans2 << '\n' ;
	return 0 ;
}

