#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 505 ;
int dp[N][N] ;
const int INF = 1e15 ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m , q;
	cin >> n >> m >> q ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i == j) continue ;
			dp[i][j] = INF ;
		}
	}
	for(int i = 0 ; i < m ; i++){
		int f , s , c ;
		cin >> f >> s >> c ;
		f-- , s-- ;
		int x = min(dp[f][s] , c) ;
		dp[f][s] = dp[s][f] = x;
	}
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ;
			}
		}
	}
	while(q--){
		int f , s ;
		cin >> f >> s ;
		f-- ,s-- ;
		cout << (dp[f][s] >= INF ? -1 : dp[f][s]) << '\n' ;
	}
	return 0 ;
}


