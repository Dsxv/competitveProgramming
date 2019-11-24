#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int* col , vector<pair<int,int>>* edges){
	queue<int> q ;
	q.push(0) ;
	unordered_map<int,int> visited ;
	while(q.size()){
		int t = q.front() ;
		q.pop() ;
		int count = -1 ;
		for(auto i : edges[t]){
			if(col[i.second] > 0)
				count = i.second ;
		}
		int c = 1 ;
		 for(auto i : edges[t]){
			if(visited.count(i.first)) continue ;
			if(i.second == count) continue ;
			if(c == col[count]) {
				col[i.second] = edges[t].size() ;
				c++ ;
			}else{
				col[i.second] = c++ ;
			}
			q.push(i.first) ;
			visited[i.first] = 1 ;
		}
	}
}


int32_t main(){
	int n; cin >> n ;
	vector<pair<int,int>> edges[n] ;
	int col[n-1] = {0} ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		edges[f].push_back({s,i}) ;
		edges[s].push_back({f,i}) ;
	}
	solve(col,edges) ;
	cout << *max_element(col,col+n-1) << endl ;
	for(auto i : col) cout << i << '\n' ;

	return 0 ;
}

