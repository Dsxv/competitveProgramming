#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
const int mod = 1e9 + 7 ;
int dp[N][2][3] ;
int l = 1e5 + 2  ;
int n , m ;

int solve(int i , int j , int k = 0){
	if(k > 2) {
		return 0 ;
	}
	if(i == l){
		return 1 ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(j == 0){
		return dp[i][j][k] = (solve(i+1,0,k+1) + solve(i+1,1,1)) % mod ;
	} else if(j == 1){
		return dp[i][j][k] = (solve(i+1,0,1) + solve(i+1,1,k+1)) % mod ;
	}
}

int val(int x){
	return (solve(l-x,0)) % mod ;
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n >> m ;
	cout << (val(n) + val(m) - 2) % mod ;
	return 0 ;
}

