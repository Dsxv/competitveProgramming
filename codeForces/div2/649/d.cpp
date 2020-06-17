#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
vector<int> G[N] ;
bool check(pair<int,int> a , pair<int,int> b){
	return a.second < b.second ;
}
int xx ;

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

bool dfs(int start , vector<int>& check , int parent = -1 , int d = 0) {
	if(d&1) {
		check.push_back(start) ;
		if(check.size() == xx) return 0 ;
	}
	for(auto i : G[start]){
		if(i == parent) continue ;
		if(!dfs(i,check,start,d+1)) return 0 ; 
	}
	return 1; 
} ;


int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	DSU dsu(n) ;
	pair<int,int> p = {-1,-1} ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
		if(dsu.merge(f,s)){
			p = {f,s} ;
		}
	}
	xx = (k+1) / 2 ;
	if(p.first == -1){
		cout << 1 << '\n' ;
		vector<int> check ;
		if(dfs(0,check)){
			check.clear() ;
			dfs(G[0].back(),check) ;
		}
		for(auto i : check) cout << i + 1 << " " ;
		return 0 ;
	}
	int visited[n] = {} ;
	int parent[n] = {} ;
	int start = p.first , x = p.second ;
	parent[x] = x ;
	queue<int> q ;
	q.push(x) ;
	visited[x] = 1 ;
	while(q.size()){
		int tp = q.front() ;
		q.pop() ;
		if(tp == start){
			break ;
		}
		for(auto i : G[tp]){
			if(tp == x && i == start) continue ;
			if(!visited[i]) {
				parent[i] = tp ;
				visited[i] = 1 ;
				q.push(i) ;
			}
		}
	}
	vector<int> v ;
	while(start != parent[start]){
		v.push_back(start) ;
		start = parent[start] ;
	}
	v.push_back(start) ;
	if(v.size() > k){
		cout << 1 << '\n' ;
		for(int i = 0 ; i < v.size() && xx ; i += 2){
			cout << v[i] + 1 << " ";
			xx-- ;
		}
		return 0 ;
	}
	cout << 2 << '\n' ;
	cout << v.size() << '\n' ;
	for(auto i : v){
		cout << i + 1 << " " ;
	}
	return 0 ;
}

