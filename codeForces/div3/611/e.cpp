#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
int dp[N][3] ;
int mp[N] ;
int n ;
int solve(int* a , int i , int j){
	if(i == n) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(
}
int32_t main(){
	cin >> n ;
	int a[n] ;
	for(int i = 0 ;  i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < N ; i++) {
		for(int j = 0 ; j < 3 ; j++) dp[i][j] = {-1,-1} ;
	}
	pair<int,int> ans = solve(a,0,0) ;
	for(int i = 0 ; i <= n + 1 ; i++) {
		for(int j = 0 ; j < 3 ; j++) cout << dp[i][j].second << " " ;
		cout << endl ;
	}
	cout << ans.second << " " << ans.first ;	
	return 0 ;
}

