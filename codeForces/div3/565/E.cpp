#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,int>* edges , unordered_map<int,int>& visited, set<int>& c1 , set<int>& c2 , int start , bool color = false){
	if(visited.count(start)) return ;
	if(color) c1.insert(start+1) ; 
	else c2.insert(start+1) ;
	visited[start] = 1 ;
	for(auto i : edges[start]){
		dfs(edges,visited,c1,c2,i.first,!color) ;
	}
}

void print(set<int> s){
	cout << s.size() << '\n' ;
	for(auto i : s ) cout << i <<' ' ;
	cout << '\n' ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ; 
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		unordered_map<int,int> edges[n] ;
		for(int i = 0 ; i < m ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			edges[f][s] = edges[s][f] =  1 ;
		}
		unordered_map<int,int> visited ;
		set<int> c1 , c2 ;
		dfs(edges,visited,c1,c2,0) ;
		if(c1.size() < c2.size()){
			print(c1) ;
		}else{
			print(c2) ;
		}
	}
 	return 0;
}

