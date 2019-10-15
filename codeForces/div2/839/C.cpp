#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10;

int val[N] ;

int leafnode ;
double ans ;

int dfs(int start , vector<int>* v , int parent , int c = 0){
	if(visited.count(start)) return 0 ;
	visited[start] = 1 ;
	for(auto i : v[
}

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> v[n] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ; cin >> f >> s ;
		f-- , s-- ;
		v[f].push_back(s) ;
		v[s].push_back(f) ;
	}
	cout << fixed << setprecision(10) << ans ;
	return 0 ;
}
