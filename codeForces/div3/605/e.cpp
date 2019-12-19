#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 20 ;

int dp[N] ;
bool active[N] ;

int solve(int* a , int i , int n , int p){
	if(i < 0 || i >= n || active[i]) return INT_MAX ;
	if(a[i]%2 == p) return 0 ;
	if(dp[i] != 0) return dp[i] ;
	active[i] = 1 ;
	dp[i] = min(solve(a,i-a[i],n,p) ,
						solve(a,i+a[i],n,p)) + 1 ;
	active[i] = 0 ;
	return dp[i] ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) {
		dp[i] =  solve(a,i,n,(a[i]+1)%2) ;
	}
	//cout << solve(a,5,n,0) << endl ;
	for(int i = 0 ; i < n ; i++) {
		if(dp[i] >= INT_MAX) cout << -1 <<" " ;
		else cout << dp[i] <<" " ;
	}
	return 0 ;
}

