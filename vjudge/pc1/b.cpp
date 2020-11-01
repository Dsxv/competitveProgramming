#include <bits/stdc++.h>
using namespace std ;

struct edge{
	int f , s , w ;
} ;

vector<int> vg ;

int getval(vector<string>& a , vector<string>& b){
	int cnt = 0 ;
	for(int i = 0 ; i < a.size() ; i++){
		for(int j = 0 ; j < a[0].size() ; j++){
			cnt += a[i][j] != b[i][j] ;
		}
	}
	return cnt ;
}

struct DSU{
	vector<int> parent , val ;
	int N ;
	DSU(){
		N = 10 ;
	}
	DSU(int n){
		N = n ;
		parent.resize(n) ;
		val.resize(n) ;
		for(int i = 0 ; i < N ; i++) {
			parent[i] = i ;
			val[i] = 1 ;
		}
	}
	int gp(int v){ //get_parent
		if(v == parent[v])
			return v ;
		return parent[v] = gp(parent[v]) ;
	}
	bool merge(int a , int b){
		a = gp(a) , b = gp(b) ;
		if(a == b) return true ;
		if(val[a] < val[b]) // a must remain the greatest!!! :p 
			swap(a,b) ;
		parent[b] = parent[a] ;
		val[a] += val[b] ;
		return false ;
	}
} ;
const int N = 1e3 + 10 ;
int visited[N] ;
void dfs(int start , vector<int>* g , vector<pair<int,int>>& ans){
	visited[start] = 1 ;
	for(auto i : g[start]){
		if(visited[i]) continue ;
		ans.push_back({start , i}) ;
		dfs(i , g , ans) ;
	}
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , k , w ;
	cin >> n >> m >> k >> w ;
	vector<string> s(n , string(m , '#')) ;
	vector<vector<string>> v ;
	v.push_back(s) ;
	for(int i = 0 ; i < k ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> s[j] ;
		}
		v.push_back(s) ;
	}
	vector<edge> g ;
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = i + 1 ; j < v.size() ; j++){
			if(i) g.push_back({i , j , w*getval(v[i] , v[j])}) ;
			else g.push_back({i , j , n*m}) ;
		}
	}
	DSU dsu(k+1) ;
	sort(g.begin() , g.end() , [&](edge a , edge b){
			return a.w < b.w ;
			}) ;
	vector<pair<int,int>> ans ;
	int cnt = 0 ;
	int cost = 0 ;
	while(ans.size() < k){
		if(!dsu.merge(g[cnt].f , g[cnt].s)) {
			ans.push_back({g[cnt].f , g[cnt].s}) ;
			cost += g[cnt].w ;
		}
		cnt++ ;
	}
	cout << cost << '\n' ;
	vector<pair<int,int>> nans ;
	vector<int> ng[k+1] ;
	for(auto i : ans) {
		ng[i.first].push_back(i.second) ;
		ng[i.second].push_back(i.first) ;
	}
	dfs(0 , ng , nans) ;
	for(auto i : nans) cout << i.second << " " << i.first << '\n' ;
	return 0 ;
}

