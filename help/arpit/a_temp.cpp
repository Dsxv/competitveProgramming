#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
vector<int> a ;

int ans ;

int solve(int start, int parent = -1){
	ans = max(ans , a[start]) ;
	vector<int> v ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		v.push_back(max(0LL , solve(i , start)))  ;
	}
	sort(v.begin() , v.end() , greater<int>()) ;
	if(v.size() == 0){
		return a[start] ;
	} else if(v.size() == 1){
		ans = max(ans , a[start] + v[0]) ;
		return a[start] + v[0] ;
	} else {
		ans = max(ans , a[start] + v[0] + v[1]) ;
		return a[start] + v[0] ;
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		g.clear() ; g.resize(n) ;
		a.clear() ; a.resize(n) ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		solve(0) ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

