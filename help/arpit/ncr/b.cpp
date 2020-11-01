#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e5 + 10 ;
int dp[N][4] ;
int n , x ;
const int INF = 1e15 ;

int solve(int * a ,  int i = 0 , int j = 0){
	if(j > 3) return INF ;
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int p = solve(a , i + 1 , j + 1) + x ;
	int q = solve(a , i + 1 , j) + a[i] ;
	if(i == 0 || i == n - 1){
		return dp[i][j] = q ;
	} else {
		return dp[i][j] = min(p , q) ;
	}
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> x ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(a) << '\n' ;
	return 0 ;
}

