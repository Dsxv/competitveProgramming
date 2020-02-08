#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 13;
int dis[N][N] ;
int dp[(1<<N)][N] ;
int n ;
int solve(int mask , int st){
	if(mask == ((1<<n) - 1)){
		return dis[st][0] ;
	}
	if(dp[mask][st] != -1) return dp[mask][st] ;
	int ans = INT_MAX ;
	for(int i = 0 ; i < n ; i++){
		if(((1<<i)&mask) == 0){
			ans = min(solve(mask|(1<<i),i) + dis[st][i] ,ans) ;
		}
	}
	return dp[mask][st] = ans ;
}

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		cin >> n ;
		memset(dp,-1,sizeof(dp)) ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cin >> dis[i][j] ;
			}
		}
		cout << solve(1,0) << endl ;
	}
	return 0 ;
}

