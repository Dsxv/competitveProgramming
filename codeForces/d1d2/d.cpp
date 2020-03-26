#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 10 ;
set<int> leaves ;
vector<int> G[N] ;
bool done[N] ;
int node[N] ;
void dfs(int start , int parent){
	if(done[start]) return ;
	done[start] = 1 ;
	if(node[start] == 1){
		leaves.erase(start) ;
		return ;
	}
	for(auto i : G[start]){
		if(i != parent){
			dfs(i,start) ;
		}
	}
}

bool check(int x , int start , int parent){
	if(done[start]) return false ;
	if(start == x) return true ;
	for(auto i : G[start]){
		if(i != parent) {
			if(check(x,i,start)) return true ;
		}
	}
	return false ;
}

void solve(int lca , int x , int y){
	for(auto i : G[lca]){
		if(check(x,i,lca) || check(y,i,lca)) {
			dfs(i,lca) ;
		}
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f ,s  ;
		cin >> f >> s ;
		f-- , s-- ;
		G[f].push_back(s) ;
		G[s].push_back(f) ;
	}
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		node[i] = G[i].size() ;
		if(node[i] == 1) leaves.insert(i) ;
	}
	int ans = -1 ;
	while((int)leaves.size() > 1){
		int x = *(leaves.begin()) , y = *(leaves.rbegin()) ;
		cout << "? "<< x+1 << " " << y+1 << endl ;
		int lca ;
		cin >> lca ;
		lca-- ;
		if(node[lca] == 2){
			ans = lca ;
			break ;
		}
		if(lca == x) {
			ans = x ;
			break ;
		}
		if(lca == y) {
			ans = y ;
			break ;
		}
		assert(node[lca] >= 2) ;
		node[lca] -= 2 ;
		if(node[lca] == 1) leaves.insert(lca) ;
		solve(lca,x,y) ;
	}
	cout <<"! "<< ans+1 << endl ;
	return 0 ;
}

