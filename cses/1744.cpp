#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 505 ;
int dp[N][N] ;

int solve(int i , int j){
	if(j > i) swap(j,i) ;
	if(i == j){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int val = INT_MAX ;
	for(int k = 1 ; k < j ; k++)
		val = min(solve(i,k) + solve(i,j-k) + 1, val) ;
	for(int k = 1 ; k < i ; k++)
		val = min(solve(j,k) + solve(j,i-k) + 1 , val) ;
	return dp[i][j] = val;
}
int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int a , b ;
	cin >> a >> b ;
	cout << solve(min(a,b) , max(a,b)) ;
	return 0 ;
}

