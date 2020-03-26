#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 5 ;

int dp[N][N] ;

int n , h , l , r ;

int solve(int* a , int i = 0 , int prev = 0){
	if(i == n){
		return	(prev >= l && prev <= r) ;
	}
	if(dp[i][prev] != -1) return dp[i][prev] ;
	int cur = prev+a[i] ;
	bool ok = (prev >= l && prev <= r && i)  ;
	return dp[i][prev] = ok + max(solve(a,i+1,cur%h),solve(a,i+1,(cur-1+h)%h)) ;
}

int32_t main(){
	cin >> n >> h >> l >> r ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	memset(dp,-1,sizeof(dp)) ;
	cout << solve(a) ;
	return 0 ;
}


