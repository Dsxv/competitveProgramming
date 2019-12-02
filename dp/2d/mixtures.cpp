#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 105 ;

int dp[N][N] ;

int32_t main(){
	int n ;
	while(cin >> n){
		int a[n+1] ;
		for(int i = 1 ;  i <= n ; i++)	cin >> a[i] ;
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= n ; j++)
				dp[i][j] = -1 ;
		}
		int pre[n] ;
		pre[0] = 0 ; pre[1] = a[1] ;
		for(int i = 2 ; i <= n ; i++) pre[i] = (a[i] + pre[i-1])%100 ;
		for(int i = n ; i >= 1 ; i--){
			for(int j = i ; j <= n ; j++){
				if(i == j){
					dp[i][j] = 0 ;
					continue ;
				}
				int	ans = INT_MAX ;
				for(int k = i ; k < j ; k++){
					int p1 = (pre[k] - pre[i-1] + 100)%100 ;
					int p2 = (pre[j] - pre[k] + 100)%100 ;
					ans = min(dp[i][k] + dp[k+1][j] + p1*p2 , ans) ;
				}
				dp[i][j] = ans ;
			}
		}
	
		cout << dp[1][n] << '\n' ;	
	}							
	return 0 ;
}

