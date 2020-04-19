#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int t){
	int n  , m  , r1 , c1 , r2 , c2 ;
	cin >> m >> n >> c1 >> r1 >> c2 >> r2 ;
	r1-- , c1-- , c2-- , r2-- ;
	double dp[n][m] = {} ;
	bool ok = false ;
	for(int i = n - 1 ; i >= 0 ; i--) {
		int j = m - 1 ;
		ok |= (i >= r1 && i <= r2 && j >= c1 && j <= c2)  ; 
		dp[i][j] = 1 - ok ;
	}
	ok = false ;
	for(int j = m - 1 ; j >= 0 ; j--) {
		int i = n - 1 ;
		ok |= (i >= r1 && i <= r2 && j >= c1 && j <= c2)  ; 
		dp[i][j] = 1 - ok ;
	}

	for(int i = n - 2 ; i >= 0 ; i--){
		for(int j = m - 2 ; j >= 0 ; j--){
			if(i >= r1 && i <= r2 && j >= c1 && j <= c2) dp[i][j] = 0 ;
			else dp[i][j] = (dp[i+1][j] + dp[i][j+1]) / 2 ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << fixed << setprecision(5) <<  dp[i][j] << " " ;
		} cout << endl ;
	}
	cout << fixed << setprecision(10) << "Case #"<<t<<": "<< dp[0][0] << '\n';
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


