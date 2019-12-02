#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 5 ;

int dp[N][N] ; 
pair<int,int> v[N];

int solve(int n , int s , int i = 0 , int j = 0){
	if(j > s) return INT_MIN ;
	if(i == n) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	int a = solve(n,s,i,j+v[i].first) ;
	int b = solve(n,s,i+1,j) ;
	return dp[i][j] = max(a + v[i].second ,b) ;
}


int32_t main(){
	int n , s ;
	cin >> n >> s ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++)
			dp[i][j] = -1 ;
	}
	for(int  i = 0 ; i < n ; i++) cin >> v[i].first ;
	for(int i = 0 ; i < n ; i++) cin >> v[i].second ;
	cout << solve(n,s) ;
	return 0 ;
}

