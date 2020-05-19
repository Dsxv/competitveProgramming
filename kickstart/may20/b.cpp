#include <bits/stdc++.h>
using namespace std ;

#define int long long

set<int> v[30] ;
int visited[30] ;
int instack[30] ;
vector<int> ans ;
bool ok = true ;

void dfs(int start){
	visited[start] = true ;
	instack[start] = true ;
	for(auto i : v[start]){
		if(instack[i]){
			ok = false ;
		}
		if(!visited[i])
			dfs(i) ;
	}
	instack[start] = false ;
	ans.push_back(start) ;
}


void gogogo(){
	memset(visited,0,sizeof(visited)) ;
	ans.clear() ;
	for(int i = 0 ; i < 30 ; i++) v[i].clear() ;
	ok = true ;
	int n , m ;
	cin >> n >> m ;
	string s[n] ;
	int count = 0 ;
	set<char> mp ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i] ;
		for(int j = 0 ; j < m ; j++) mp.insert(s[i][j]) ;
	}
	for(int j = 0 ; j < m ; j++){
		for(int i = n - 1 ; i > 0 ; i--){
			if(s[i][j] != s[i-1][j]){
				v[s[i][j] - 'A'].insert(s[i-1][j]-'A') ;
			}
		}
	}

	for(auto i : mp){
		if(!visited[i-'A'])
			dfs(i-'A') ;
	}
	reverse(ans.begin(),ans.end()) ;
	if(!ok) cout << -1 << '\n' ;
	else {
		for(auto i : ans) cout << (char)(i+'A') ;
		cout << '\n' ;
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


