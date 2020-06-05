#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
vector<int> g[N] ;
struct node{
	int a , b , c ;
} v[N] ;
int ans ;

pair<int,int> dfs(int start , int parent = -1, int mn = INT_MAX){
	pair<int,int> val = {0,0} ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		auto temp = dfs(i,start,min(mn , v[start].a)) ;
		val.first += temp.first ;
		val.second += temp.second ;
	}
	if(v[start].b != v[start].c){
		val.first += !v[start].b ;
		val.second += v[start].b ;
	}

	if(v[start].a < mn){
		int x = min(val.first , val.second) ;
		ans += x * (v[start].a) * 2 ;
		val.first -= x ;
		val.second -= x ;
	}
	return val ;
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		cin >> v[i].a >> v[i].b >> v[i].c ;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	pair<int,int> val = dfs(0) ;
	if(val.first != val.second){
		cout << -1 ;
	} else {
		cout << ans ;
	}
	return 0 ;
}

