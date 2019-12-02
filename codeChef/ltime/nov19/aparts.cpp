#include <bits/stdc++.h>
using namespace std ;

#define int long long


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int dp[n+2][m+2] = {} ;
		int a[n+1][m+2] ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++) cin >> a[i][j] ;
		}
		for(int i = 1; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				dp[i][j] = max({dp[i-1][j-1] , dp[i-1][j] ,
								dp[i-1][j+1] , a[i][j]}) ;
			}
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				if(dp[i][j] == a[i][j]) cout << 1 ;
				else cout << 0 ;
			} cout << '\n' ;
		}
	}
	return 0 ;
}

