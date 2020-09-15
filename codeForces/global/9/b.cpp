#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {0,0,-1,1} ;
int yy[4] = {1,-1,0,0} ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n  , m ;
		cin >> n >> m ;
		int a[n][m] ;
		bool found = true ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> a[i][j] ;
			}
		}
		int dp[n][m] = {} ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(i == n - 1 || j == m - 1 || i == 0 || j == 0){
					dp[i][j] = 3 ;
				} else {
					dp[i][j] = 4 ;
				}
			}
		}
		dp[0][0] = dp[n-1][m-1] = dp[0][m-1] = dp[n-1][0] = 2 ; 
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(a[i][j] > dp[i][j]) found = false ;
			}
		}
		if(!found) { cout << "NO\n" ; continue ; }
		cout << "YES\n" ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout << dp[i][j] << " \n"[j == m - 1] ;
			}
		}
	}
	return 0 ;
}

