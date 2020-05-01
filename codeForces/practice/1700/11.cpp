#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e3 + 10;
int dp[N][N] ;
int n , m , k ;
int inf = 1e16 ;
int pre[N] ;

int sum(int l){
	int r = l + m - 1 ;
	if(r >= n) return -inf ;
	if(l == 0){
		return pre[r] ;
	} else {
		return pre[r] - pre[l-1] ;
	}
}
int solve(int* a , int i = 0 , int j = 0){
	if(j > k || i > n){
		return -inf ;
	}
	if(i == n){
		if(j == k) return 0 ;
		else return -inf ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	return dp[i][j] = max(solve(a,i+1,j) , solve(a,i+m,j+1) + sum(i)) ;
}

int32_t main(){
	cin >> n >> m >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	pre[0] = a[0] ;
	for(int i = 1 ; i < n ; i++) pre[i] = pre[i-1] + a[i] ;
	memset(dp,-1,sizeof(dp)) ;
	cout << solve(a) ;
	return 0 ;
}

