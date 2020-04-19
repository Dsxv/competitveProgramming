#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
vector<int> G[N] ;
int visited[N] ;
int children[N] ;
int dd[N] ;
map<int,int> pr ;
int ans ;
int dfs(int start , int parent = -1 , int dis = 0){
	pr[start] = parent ;
	dd[start] = dis ;
	if(G[start].size() == 1 && parent != -1){
		return 1 ;
	}
	int ans = 0 ;
	for(auto i : G[start]){
		if(i != parent)
		ans += dfs(i,start , dis + 1) ;
	}
	children[start] = ans ;
	return ans + 1 ;
}

int32_t main(){
	int n , k ; 
	cin >> n >> k ;
	memset(visited, -1 , sizeof(visited)) ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	dfs(0) ;
	int b[n] ;
	for(int i = 0 ; i < n ; i++) b[i] = dd[i] - children[i] ;
	sort(b,b+n,greater<int>()) ;
	cout << accumulate(b,b+k,0LL) ;
	return 0 ;
}

