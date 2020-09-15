#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;

int dp[N][4] ;

int a[N][3] ;
int n ;

int solve(int i = 0 , int j = 0){
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int ans = 0 ;
	for(int x = 1 ; x <= 3 ; x++){
		if(x == j) continue ;
		ans = max(ans , solve(i + 1 , x) + a[i][x-1]) ;
	}
	return dp[i][j] = ans ;
}

int32_t main(){
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 3 ; j++) cin >> a[i][j] ;
	}
	cout << solve() ;
	return 0 ;
}

