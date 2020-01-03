#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 5 ;
int dp[4][N][N] ;
int a[N][N] ;
int n , m ;

void print(){
	for(int k = 0 ; k < 4 ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cout << dp[k][i][j] << " " ;
			} cout << endl ;
		} cout << "-----\n\n" ;
	}
}

int solve(){
	for(int i = 1 ; i <= n ; i++) dp[0][i][1] = dp[0][i-1][1] + a[i][1] ;
	for(int j = 1 ; j <= m ; j++) dp[0][1][j] = dp[0][1][j-1] + a[1][j];
	for(int i = 2 ; i <= n ; i++){
		for(int j = 2 ; j <= m ; j++){
			dp[0][i][j] = a[i][j] + max(dp[0][i-1][j] , dp[0][i][j-1]) ;
		}
	}
	for(int i = 1 ; i <= n ; i++) dp[1][i][m] = dp[1][i-1][m] + a[i][m] ;
	for(int j = m ; j >= 1 ; j--) dp[1][1][j] = dp[1][1][j+1] + a[1][j] ;
	for(int i = 2 ; i <= n ; i++){
		for(int j = m - 1 ; j >= 1 ; j--){
			dp[1][i][j] = a[i][j] + max(dp[1][i-1][j] , dp[1][i][j+1]) ;
		}
	}
	for(int i = n ; i >= 1 ; i--) dp[2][i][1] = dp[2][i+1][1] + a[i][1] ;
	for(int j = 1 ; j <= m ; j++) dp[2][n][j] = dp[2][n][j-1] + a[n][j] ;
	for(int i = n - 1 ; i >= 1 ; i--){
		for(int j = 2 ; j <= m ; j++){
			dp[2][i][j] = a[i][j] + max(dp[2][i+1][j] , dp[2][i][j-1]) ;
		}
	}
	for(int i = n ; i >= 1 ; i--) dp[3][i][m] = dp[3][i+1][m] + a[i][m] ;
	for(int j = m ; j >= 1 ; j--) dp[3][n][j] = dp[3][n][j+1] + a[n][j] ;
	for(int i = n - 1 ; i >= 1;  i--){
		for(int j = m - 1 ; j >= 1 ; j--){
			dp[3][i][j] = a[i][j] + max(dp[3][i+1][j] , dp[3][i][j+1]) ;
		}
	}

	int ans = 0 ;
	int i1 , j1 ;
	for(int i = 2 ; i < n ; i++){
		for(int j = 2 ; j < m ; j++){
			int m1 = dp[0][i][j-1] + dp[3][i][j+1] + dp[1][i-1][j] + dp[2][i+1][j] ;
			int m2 = dp[0][i-1][j] +  dp[3][i+1][j] + dp[1][i][j+1] + dp[2][i][j-1] ;
			ans = max({ans,m1,m2}) ;
		}
	}
	return ans ;
	//print() ;
}
int32_t main(){
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j] ;
		}
	}
	
	cout << solve() ;
	return 0 ;
}

