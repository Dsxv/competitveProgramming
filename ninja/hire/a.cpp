#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[4][4][4] ;
int ans = 0 ;

int solve(int i = 0 , int j = 0 , int k = 0){
	if(i == 3){
		return 1 ;
	}
	//if(~dp[i][j][k]) return dp[i][j][k] ;

	int ans = 0 ;
	for(int x = 0 ; x < 3 ; x++){
		for(int y = 0 ; y < 3 ; y++){
			if(x == j || y == k || x == y) continue ;
			ans += solve(i + 1 , x , y) ;
		}
	}
	return dp[i][j][k] = ans ;
}


int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cout << solve() ;
	return 0 ;
}

