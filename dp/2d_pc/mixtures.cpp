#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 105 ;
int dp[N][N] ;
int n ;
int col[N] ;
int solve(int* a , int i , int j){
	if(i == j) return 0 ;
	if(abs(i-j) == 1) return a[i]*a[j] ;
	if(dp[i][j] != -1) return dp[i][j] ;
	dp[i][j] = INT_MAX ;
	for(int k = i ; k < j ; k++){
		int c1 = (col[k] - col[i-1] + 100) % 100;
		int c2 = (col[j] - col[k] + 100) % 100 ;
		dp[i][j] = min(c1*c2 + solve(a,i,k) + solve(a,k+1,j) , dp[i][j]) ;
	}
	return dp[i][j] ;
}

int32_t main(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++) dp[i][j] = -1 ;
	}
	cin >> n ;
	int a[n+1] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
	col[1] = a[1];
	for(int i = 1 ; i < n ; i++) col[i+1] = (col[i] + a[i+1])%100 ;
	cout << solve(a,1,n) ;
	return 0 ;
}

