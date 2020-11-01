#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 ;
vector<int> g[N] ;
map<string , int> mp ;
vector<string> v ;
bool instack[N] ;

void dfs(int start){
	instack[start] = true ;
	cout << v[start] << '\n' ;
	for(auto i : g[start]){
		if(instack[i]) continue ;
		dfs(i) ;
	}
	instack[start] = false ;
}

int32_t main(){
	int m ;
	cin >> m ;
	int cnt = 0 ;
	for(int i = 0 ; i < m ; i++){
		string f , s;
		cin >> f >> s ;
		if(!mp.count(f)){
			mp[f] = cnt++ ;
			v.push_back(f) ;
		}
		if(!mp.count(s)){
			mp[s] = cnt++ ;
			v.push_back(s) ;
		}
		int x = mp[f] , y = mp[s] ;
		g[x].push_back(y) ;
	}
	string temp ; cin >> temp ;
	int start = mp[temp] ;
	dfs(start) ;
	return 0 ;
}

