#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e4 + 10 ;
vector<int> g[N] ;
int val[N] ;
int dfs(int start){
	vector<int> v ;
	for(auto i : g[start]){
		v.push_back(dfs(i)) ;
	}
	sort(v.begin() , v.end() , greater<int>()) ;
	int x = 0 ;
	for(int i = 0 ; i < v.size() ; i++){
		x = max(v[i] + i + 1 , x) ;
	}
	return val[start] = x ;
}


int32_t main(){
	int n , m ;
	cin >> n >> m ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		g[f].push_back(s) ;
	}
	cout << dfs(0) ;
	for(int i = 0 ; i < n ; i++) cout << val[i] << " " ;
	return 0 ;
}

