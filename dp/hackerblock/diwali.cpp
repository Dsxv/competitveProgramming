#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 105 ;
const int mod = 1e6 + 3 ;
int dp[N][N][2] ;

int solve(int n , int k , int i = 0 , int j = 0 , int prev = 0){
	if(i == n){
		if(j == k) return 1 ;
		return 0 ;
	}
	if(dp[i][j][prev] != -1) return dp[i][j][prev] ;
	return dp[i][j][prev] = ( solve(n,k,i+1,j+prev,1) 
						+ solve(n,k,i+1,j,0) ) % mod ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k  ;
		cin >> n >> k ;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++) 
				dp[i][j][0] = dp[i][j][1] = -1 ;
		}
		cout << solve(n,k) << '\n' ;
	}
	return 0 ;
}

