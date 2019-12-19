#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[105][105][11][11] ;
const int mod = 1e8 ;


int solve(int n1 , int n2 , int k1 , int k2 , int i = 0 , int j = 0 , int k = 0 , int l = 0 ) {
	if(i > n1 || j > n2 || k > k1 || l > k2) return 0 ;
	if(i == n1 && j == n2) return 1 ;
	if(dp[i][j][k][l] != -1) return dp[i][j][k][l] ;
	return dp[i][j][k][l] = 
		(solve(n1,n2,k1,k2,i+1,j,k+1,0) + solve(n1,n2,k1,k2,i,j+1,0,l+1))%mod ;
}

int32_t main(){
	int n1 , n2 , k1 , k2 ;
	cin >> n1 >> n2 >> k1 >> k2 ;
	for(int i = 0 ; i <= n1 ; i++){
		for(int j = 0 ; j <= n2 ; j++){
			for(int k = 0 ; k <= k1 ; k++){
				for(int l = 0 ; l <= k2 ; l++){
					dp[i][j][k][l] = -1 ;
				}
			}
		}
	}
	cout << solve(n1,n2,k1,k2) ;
	return 0 ;
}

