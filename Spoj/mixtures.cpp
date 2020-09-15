#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[105][105] ;
int a[105] ;
int sum[105] ;
int val(int l , int r){
	int x = 0 ;
	if(l) x = sum[l-1] ;
	return ( sum[r] - x + 100 ) % 100 ;
}

int solve(int i , int j){
	if(j <= i) return 0 ;
	if(~dp[i][j]) return dp[i][j] ;
	int ans = LLONG_MAX ;
	for(int k = i ; k < j ; k++){
		ans = min( solve(i,k) + solve(k+1,j) + val(i,k)*val(k+1,j) , ans) ;
	}
	return dp[i][j] = ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n; 
	while(cin >> n){
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++){
			sum[i] = 0 ;
			if(i) sum[i] = sum[i-1] ;
			sum[i] = (sum[i] + a[i]) % 100 ;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++) dp[i][j] = -1 ;
		}
		cout << solve(0,n-1) << '\n' ;
	}
	return 0 ;
}

