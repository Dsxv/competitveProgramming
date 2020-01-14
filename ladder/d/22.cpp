#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 , mod = 1e9 + 7;

int dp[3][N] ;

int add(int x , int y){
	x += y ;
	if(x >= mod) x -= mod ;
	return x ;
}

int32_t main(){
	int r , g ;
	cin >> r >> g ;
	int ans = 0 , h = 0;
	for(int i = 1 ; i < 1000 ; i++){
		ans += i ;
		if(ans > r + g) break ;
		h = i ;
	} 
	dp[0][0] = 1 ;
	for(int i = 1 ; i <= h ; i++){
		for(int j = 0 ; j <= r ; j++){
			dp[i%2][j] = 0 ;
			if(g >= (i*(i+1)/2-j)) dp[i%2][j] = dp[1-i%2][j] ;
			if(j >= i) dp[i%2][j] = add(dp[1-i%2][j-i] , dp[i%2][j]);
		}
	}
	int sum = 0 ;
	for(int i = 0 ; i <= r ; i++) {
		sum = add(sum , dp[h%2][i]) ;
	}
	cout << sum ;	
	return 0 ;
}

