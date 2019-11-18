#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

#define int long long 

const ll mod  = 998244353 ;

const int N = 2e3 + 5 ;

int dp[N][N] , n , m , k ;

 
int solve(int i ,int j){
	if(j < 0 ) return 0 ;
	if(i == n){
		if(j) return 0 ;
		else return 1 ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	if(i == 0){
		dp[i][j] = (solve(i+1,j)*m )%mod ;
	}else{
		dp[i][j] = (solve(i+1,j) + solve(i+1,j-1)*(m-1))%mod ;
	}
	return dp[i][j] ;
}


int32_t main(){
	cin >> n >> m >> k ;
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= k ; j++) dp[i][j] = -1 ;
	cout << solve(0,k) ;
	return 0 ;
}

