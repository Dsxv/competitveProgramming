#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 2 , M = 1e5 + 10 ;
const int mod = 1e9 + 7 ;

int dp[N][M] ;
int n , k ;
int msum ;
int solve(int* a , int i = 0 , int j = 0){
	if(j > msum){
		return 0 ;
	}
	if(i == n){
		return (j >= k && j < msum) ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;

	return dp[i][j] = (solve(a,i+1,j+a[i]) + solve(a,i+1,j)) % mod ;
}
	

int32_t main(){
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	memset(dp,-1,sizeof(dp)) ;
	msum = accumulate(a,a+n,0LL) - k;
	cout << solve(a) ;
	return 0 ;
}

