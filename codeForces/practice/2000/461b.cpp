#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;
int ans = 1 ;
const int mod = 1e9 + 7 , N = 1e5 + 10;
int a[N] ;
int dp[N][2] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

void solve(int start , int parent = -1){
	int total = 1 ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve(i , start) ;
		int x = ( dp[i][0] + dp[i][1] ) % mod  ;
		total = (total*x) % mod ;
	}
	if(a[start]){
		dp[start][0] = 0 ;
		dp[start][1] = total ;
	} else {
		dp[start][0] = total ;
		for(auto i : g[start]){
			if(i == start) continue ;
			int x = (dp[i][0] + dp[i][1]) % mod;
			x = (total*modexp(x , mod - 2)) % mod ;
			dp[start][1] = ( dp[start][1] + x*dp[i][1]) % mod ;
		}
	}
}

int32_t main(){
	int n; cin >> n ;
	g.resize(n) ;
	for(int i = 1 ; i < n ; i++){
		int x ; cin >> x ;
		g[x].push_back(i) ;
		g[i].push_back(x) ;
	}
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
	}
	solve(0) ;
	cout << dp[0][1] ;
	return 0 ;
}

