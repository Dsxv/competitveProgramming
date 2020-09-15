#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N  = 1e5 + 10 ;
vector<int> g[N] ;
int dp[N] ;
int a[N] ;

void solve(int start , int parent = -1){
	int a = 0 , b = 0 ;
	vector<int> v ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve(i , start) ;
		v.push_back(i) ;
	}
	for(auto i : v) a += dp[i] ;
	for(auto i : v){
		for(auto j : g[i]){
			if(j == i) continue ;
			b += dp[j] ;
		}
	}
	dp[start] = max(a , b + ::a[start]) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		g[f].push_back(s) ;
		g[s].push_back(f) ;
	}
	solve(0) ;
	cout << dp[0] << '\n' ;
	return 0 ;
}

