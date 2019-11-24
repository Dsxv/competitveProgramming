#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 5 ;

int dp[N][N] ;

int solve(int* a , int i , int j , int y = 1){
	if(i == j){
		return y*a[i] ;
	}
	if(dp[i][j] != -1){
		return dp[i][j] ;
	}
	int fr = solve(a,i+1,j,y+1) + y*a[i] ;
	int bk = solve(a,i,j-1,y+1) + y*a[j] ;
	return dp[i][j] = max(fr,bk) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) dp[i][j] = -1 ;
	}
	cout << solve(a,0,n-1) ;
	return 0 ;
}

