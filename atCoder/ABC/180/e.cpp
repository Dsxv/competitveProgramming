#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> a ;

int dp[17][1 << 17] ;
int n ;
int val(vector<int>& x , vector<int>& y){
	return abs(x[0] - y[0]) + abs(x[1] - y[1]) + max(0LL , y[2] - x[2]) ;
}

int solve(int start = 0 , int mask = 1){
	if(mask == ((1 << n) - 1)){
		return val(a[start] , a[0]) ;
	}
	if(~dp[start][mask]) return dp[start][mask] ;
	int ans = 1e15 ;
	for(int i = 0 ; i < n ; i++){
		if(mask & (1 << i)) continue ;
		ans = min(ans , val(a[start] , a[i]) + solve(i , mask | (1 << i)) ) ;
	}
	return dp[start][mask] = ans ;
}

int32_t main(){
	cin >> n ;
	a.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		a[i].resize(3) ;
		for(auto &j : a[i]) cin >> j ;
	}
	memset(dp , -1 , sizeof(dp)) ;
	cout << solve() ;
	return 0 ;
}

