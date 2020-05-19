#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int inf = 1e16 ;
const int N = 105 ;
int dp[N][N][N] ;

int a[N] ;
int col[N][N] ;
int n , m , kk ;

int solve(int i = 0 , int j = 0 , int k = 0){
	if(i == n){
		if(k == kk) return 0 ;
		else return inf ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(a[i]){
		return dp[i][j][k] = solve(i+1,a[i],k+(a[i]!=j)) ;	
	} else {
		dp[i][j][k] = inf ;
		for(int x = 1 ; x <= m ; x++){
			dp[i][j][k] = min(dp[i][j][k] , col[i][x] + solve(i+1,x,k+(x!=j))) ;
		}
		return dp[i][j][k] ;
	}
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n >> m >> kk ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> col[i][j+1] ;
		}
	}
	int x = solve() ;
	if(x >= inf){
		cout << -1 ;
	} else {
		cout << x ;
	}
	return 0 ;
}

