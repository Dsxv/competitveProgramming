#include <bits/stdc++.h>
using namespace std ;

#define int long long
	
const int N = 1e5 + 5 ;
const int mod = 1e9 + 7 ;
int dp[N][12] ;
int ans ;
int n ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int gs(int ind , int x , int cnt){
	ans = (ans +  (cnt*(x*modexp(10 , n-ind-1))%mod ) % mod ) % mod ; 
}

int solve(int i , int j , int prev , int v){
	if(i > j){
		return prev == 0;
	}
	if(dp[i][prev] != -1) return dp[i][prev] ;
	dp[i][prev] = 0 ;
	for(int x = 1 ; x < 10 ; x++){
		int val = x ;
		if(i != j) val += x ;
		dp[i][prev] = (solve(i+1,j-1,(prev+val)%9,x) + dp[i][prev]) % mod ;
	}
	gs(i,v,dp[i][prev]) ;
	if(i != j) gs(j,v,dp[i][prev]) ;
	return dp[i][prev] ;
}
		
int32_t main(){
	cin >> n ;
	memset(dp,-1,sizeof(dp)) ;
	solve(0,n-1,0,0) ;
	cout << ans ;
	return 0 ;
}

