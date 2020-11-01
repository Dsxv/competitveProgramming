#include <bits/stdc++.h>
using namespace std ;

const int N = 1e3 + 10 ;
char ch[N][N] ;
int dx[4] = {0 , 0 , -1 , 1} ;
int dy[4] = {-1 , 1 , 0 , 0} ;
map<pair<int,int> , pair<int,int>> parent ;
map<pair<int,int> , map<pair<int,int> , int>> g ;
int n , m ;

void dfs(pair<int,int> cur , pair<int,int> p){
	for(int i = 0 ; i < 4 ; i++){
		int cx = cur.first + dx[i] ;
		int cy = cur.second + dy[i] ;
		if(cx < 0 || cx >= n || cy < 0 || cy >= m || ch[cx][cy] == '#') continue ; 
		if(parent.count({cx,cy})) continue ;
		parent[{cx , cy}] = p ;
		dfs({cx , cy} , p) ;
	}
}

int	bfs(pair<int,int> s , pair<int,int> d){
	queue<pair< pair<int,int>  , int>> q ;
	q.push({s , 0}) ;
	map<pair<int,int> , int> visited ;
	visited[s] = true ;
	while(q.size()){
		auto [cur , dis] = q.front() ;
		q.pop() ;
		if(cur == d) return dis;
		for(auto i : g[cur]){
				if(visited[i.first]) continue ;
				visited[i.first] = 1 ;
				q.push({i.first , dis + 1}) ;
		}
	}
	return -1 ;
}

int32_t main(){
	cin >> n >> m ;
	pair<int,int> s , d ;
	cin >> s.first >> s.second ;
	cin >> d.first >> d.second ;
	s.first-- , s.second-- ;
	d.first-- , d.second-- ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> ch[i][j] ;
		}
	}
	for(int i = 0  ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(ch[i][j] == '#') continue ;
			if(parent.count({i,j})) continue ;
			dfs({i,j} , {i,j}) ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!parent.count({i,j})) parent[{i,j}] = {i,j} ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int p = i - 2 , q = j - 2 ;
			if(ch[i][j] == '#') continue ;
			for(int f = p ; f < p + 5 ; f++){
				for(int s = q ; s < q + 5 ; s++){
					if(f < 0 || f >= n || s < 0 || s >= m) continue ;
					if(ch[f][s] == '#') continue ;
					g[parent[{i,j}]][parent[{f,s}]] = 1 ;
				}
			}
		} 
	}
	cout << bfs(parent[s],parent[d]) ;
	return 0 ;
}

