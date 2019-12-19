#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N =  2e3 + 5 ;
const int mod = 1e9 + 7 ;

int dp[N][N] ;

int solve(int k , int n , int i = 0 , int j = 1){
	if(i == k){
		return j <= n ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	dp[i][j] = 0 ;
	for(int x = j ; x <= n ; x+=j)
		dp[i][j] =  ( dp[i][j] + solve(k,n,i+1,x) ) % mod ;
	return dp[i][j] ;
}

int32_t main(){
	int n , k ; 
	cin >> n >> k ;
	for(int i = 0 ; i  <= k; i++){
		for(int j = 0 ; j <= n ; j++) 
			dp[i][j] = -1 ;
	}
	cout << solve(k,n) ;
	return 0 ;
}

