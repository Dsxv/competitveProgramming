#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 3e5 + 10 ;
const int minf = -1e18 ;
int dp[N][3][2] ;
int n , x ;
int ans ;

int solve(int* a , int i = 0 , int j = 0 , bool k = 0){
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(j == 0){
		return dp[i][j][k] = max(0LL , max({solve(a,i+1,0,0) , solve(a,i,1,0) , solve(a,i,1,1)})) ;
	} if(j == 1) {
		if(k == 0){
			return dp[i][j][k] = max(0LL , a[i] +  max({solve(a,i+1,1,0) ,solve(a,i+1,1,1) , 0LL})) ;
		} else {
			return dp[i][j][k] = max(0LL , a[i]*x + max({solve(a,i+1,1,1),solve(a,i+1,2,0)})) ;
		}
	} else {
		return dp[i][j][k] = max(0LL , a[i] +  solve(a,i+1,2,0)) ;
	}
}

int32_t main(){
	cin >> n >> x ;
	int a[n] ;
	memset(dp,-1,sizeof(dp)) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	cout << solve(a) ;
	return 0 ;
}
