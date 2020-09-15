#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e4 + 5 ;
const int INF = 1e15 ;
int dp[N][N][2] ;
int a[N][3] ;
int n , m; 

int solve(int i = 0 , int j = 0 , int k = 0 , int ca = 0 , int cb = 0 , int cc = 0){
	if(j == m){
		return ca + cb + cc ;
	}
	if(i == n){
		return INF ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	int xa = max(ca , a[i][0]) , xb = max(cb , a[i][1]) , xc = max(cc , a[i][2]) ;
	return dp[i][j][k] = min(solve(i + 1 , j + 1 , 1

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> m ;
	
	cout << solve() ;
	return 0 ;
}

