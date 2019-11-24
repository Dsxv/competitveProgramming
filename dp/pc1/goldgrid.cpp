#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 5 ;

int a[N][N] , dp[N][N] , row[N] , col[N] ;

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int t = m ;
	while(m--){
		int x , y ;
		cin >> x >> y ;
		x-- , y-- ;
		a[x][y] = 1 ;
	}
	m = t ;
	for(int i = 0 ; i < n ; i++){ 
		dp[i][0] = dp[i-1][0] + a[i][0] ,
		dp[0][i] = dp[0][i-1] + a[0][i] ;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) 
			row[i] += a[i][j] , col[i] += a[j][i] ;
		if(i > 0)	
			row[i] += row[i-1] , col[i] += col[i-1] ;
	}


	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < n ; j++){
			dp[i][j] = a[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] ;
		}
	}
	int ans = 0 ;

	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < n - 1 ; j++){
			int a = row[j] - dp[i][j] ;
			int b = col[i] - dp[i][j] ;
			int c = m - a - b - dp[i][j] ;
			//printf("%d:%d:%d:%d ",a,b,c,dp[i][j]) ;
			ans = max(ans,min({a,b,c,dp[i][j]})) ;
		}
	}
	cout << ans ;

	return 0 ;
}

