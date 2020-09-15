#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e3 + 10 ;
int n , k ;
int dp[N] , cost[N][N] ;

int solve(int i = 0){
	if(i == n) return 0 ;
	if(~dp[i]) return dp[i] ;
	dp[i] = LLONG_MAX ;
	for(int j = i ; j < n ; j++){
		dp[i] = min(dp[i] , k + cost[i][j] + solve(j+1)) ;
	}
	return dp[i] ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> k ;
		int a[n] ;
		memset(dp , -1 , sizeof(dp)) ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++){
			int fi[101] = {} ;
			int tc = 0 ;
			for(int j = i ; j < n ; j++){
				if(fi[a[j]] > 1){
					tc++ ;
				} else if(fi[a[j]] == 1){
					tc += 2 ; fi[a[j]]++ ;
				} else {
					fi[a[j]]++ ;
				}
				cost[i][j] = tc ;
			}
		}
		cout << solve() << '\n' ;
	}
	return 0 ;
}

