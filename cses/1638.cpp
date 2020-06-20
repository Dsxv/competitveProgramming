#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
int32_t main(){
	int n ;
	cin >> n ;
	int dp[n][n] = {} ;
	char ch[n][n] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> ch[i][j] ;
		}
	}
	dp[n-1][n-1] = (ch[n-1][n-1] != '*') ;
	for(int j = n - 2 , i = n - 1 ; j >= 0 ; j--){
		dp[i][j] = (dp[i][j+1] && ch[i][j] != '*') ;
		dp[j][i] = (dp[j+1][i] && ch[j][i] != '*') ;
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		for(int j = n - 2 ; j >= 0 ; j--){
			dp[i][j] = (dp[i+1][j] + dp[i][j+1])*(ch[i][j] != '*') ;
			dp[i][j] %= mod ;
		}
	}
	cout << dp[0][0] ;
	return 0 ;
}

