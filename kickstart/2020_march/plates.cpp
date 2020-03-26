#include <bits/stdc++.h>
using namespace std ;


long long dp[55][1505] ;

int n , k , p ;

long long solve(vector<vector<int>> & v , int i = 0 , int j = 0){
	if(i == n){
		if(j == p) return 0 ;
		return INT_MIN ;
	}
	if(dp[i][j] != -1){
		return dp[i][j] ;
	}
	dp[i][j] = solve(v,i+1,j) ;
	int val = 0 ;
	for(int x = 0 ; x < k ; x++){
		if((j + x + 1) <= p){
			val += v[i][x] ;
			dp[i][j] = max(dp[i][j],solve(v,i+1,j+x+1)+val) ;
		}
	}
	return dp[i][j] ;
}


int32_t main(){
	int t ;
	cin >> t ;
	for(int x = 1 ; x <= t ; x++){
		memset(dp,-1,sizeof(dp)) ;
		cin >> n >> k >> p;
		vector<vector<int>> v(n,vector<int>(k)) ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < k ; j++){
				cin >> v[i][j] ;
			}
		}
		int ans =  solve(v) ;
		printf("Case #%d: %d\n",x,ans) ;
	}
	return 0 ;
}

