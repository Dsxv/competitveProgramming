#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 1 ;
const int mod = 1e9 + 7 ;
int dp[101][N] ;

int main(){
	int n , x ;
	cin >> n >> x ;
	int a[n] = {};
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) dp[i][0] = 1  ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 1 ; j <= x ; j++){
			if(i > 0){
				dp[i][j] += dp[i-1][j] ;
			}
			if(j >= a[i]){
				dp[i][j] += dp[i][j-a[i]] ;
			}
			dp[i][j] %= mod ;
		}
	}
	cout << dp[n-1][x] ;
	return 0 ;
}



