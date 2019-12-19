#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int dp[N] ;

int solve(int n ,int x , int y , int z) {
	if(n == 1) return 0 ;
	if(dp[n] != -1) return dp[n] ;
	if(n&1){
		dp[n] = min(solve(n-1,x,y,z) + y , solve((n+1)/2,x,y,z) + z + x) ;
	} else {
		dp[n] = min(solve(n-1,x,y,z) + y , solve(n/2,x,y,z) + x) ;
	}
	return dp[n] ;
}

int32_t main(){
	for(int i = 0 ; i < N ; i++) dp[i] = -1 ;
	int n , x , y , z ;
	cin >> n >> x >> y >> z ;
	cout << solve(n,x,y,z) ;
	return 0 ;
}

