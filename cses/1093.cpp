#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 500 , M = 500*250 ;
int dp[N][M] ;
const int mod = 1e9 + 7 ;

int solve(int n , int m , int i = 0 , int j = 0){
	if(2*j > m){
		return 0 ;
	}
	if(i == n){
		return 2*j == m ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	return dp[i][j] = (solve(n,m,i+1,j+(i+1)) + solve(n,m,i+1,j)) % mod ; 
}

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1 ) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int n ;
	cin >> n ;
	int m = n*(n+1)/2 ;
	cout << (solve(n,m)*modexp(2,mod-2))%mod;
	return 0 ;
}

