#include <bits/stdc++.h>
using namespace std ;

#define int long long 

const int N  = 2e5 + 10;
int dp[2][N] ;
int n ;
int a[N] ;
int instack[2][N] ;

// 0 means -ve direction
// 1 means +ve direction

int dfs(int dir , int x){
	if(x < 0 || x >= n) return 0 ;
	if(dp[dir][x] != -2) return dp[dir][x] ;
	if(instack[dir][x]) {
		return dp[dir][x] = -1 ;
	}

	instack[dir][x] = true ;
	
	int val ;
	if(dir){
		val = dfs(!dir , x + a[x]) ;
	} else {
		val = dfs(!dir , x - a[x]) ;
	}
	if(val == -1){
		return dp[dir][x] = -1 ;
	}
	instack[dir][x] = false ;
	return dp[dir][x] = a[x] + val ;

}

int32_t main(){ 
	cin >> n ;
	for(int i = 1 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < n ; j++) dp[i][j] = -2 ;
	}
	instack[1][0] = true ;
	for(int i = 1 ; i < n ; i++){
		dfs(0,i) ;
		dfs(1,i) ;
	}
	for(int i = 1 ; i < n ; i++){
		if(~dp[0][i]){
			cout << i + dp[0][i] << '\n' ;
		} else {
			cout << -1 << '\n' ;
		}
	}
	return 0 ;
}

