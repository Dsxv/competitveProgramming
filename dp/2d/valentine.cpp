#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e3 + 10 ;

int dp[N][N] ;
int n , m ;

int solve(int* b , int* g , int i = 0 , int j = 0){
	if(i == n || j == m) return 0 ;

	if(n-i == m-j){
		int sum = 0 ;
		for(int k = 0 ; k < n-i ; k++){
			sum += abs(b[i+k]-g[j+k]) ;
		}
		return dp[i][j] = sum ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	return dp[i][j] = min(abs(b[i]-g[j]) + solve(b,g,i+1,j+1),
							solve(b,g,i,j+1) ) ;
}
						  

int solve_itr(int* b , int* g){
	int c = 1 ;
	m--,n-- ;
	for(int i = n ; i >= 0 ; i--,c++){
		for(int j = 0 ; j < c ; j++){
			dp[i][m-c] += abs(b[n-j]-g[m-j]) ; 
		} 
		for(int j = m-c-1 ; j >= i ; j--){
			dp[i][j] = min(dp[i][j+1],dp[i+1][j+1] + abs(b[i]-g[j])) ;
		}
	}
	cout <<  dp[0][0] ;
}


int32_t main(){
	cin >> n >> m ;
	int b[n] , g[m] ;
	// for(int i = 0 ; i < n + 2 ; i++)
	// 	for(int j = 0 ; j < m + 2 ; j++) dp[i][j] = -1 ;

	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	for(int i = 0 ; i < m ; i++) cin >> g[i] ;
	sort(b,b+n) ; sort(g,g+m) ;
	solve_itr(b,g) ;
	// cout << solve(b,g) ;
	return 0 ;
}

