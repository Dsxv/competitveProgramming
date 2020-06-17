#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int INF = 1e18 ;
const int N = 1e5 + 10 ;

int dp[N][5] ;

int a[N] ;
int n , m = 4 ;

int solve(string&s , string&t , int i = 0 , int j = 0){
	if(j == m){
		return INF ;
	}
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	if(s[i] != t[j]){
		return dp[i][j] = solve( s , t , i + 1 , j) ;
	} else {
		return dp[i][j] = min(solve(s,t,i+1,j+1) , solve(s,t,i+1,j) + a[i]) ;
	}
}
	
int32_t main(){
	cin >> n ;
	string s , t ;
	cin >> s ;
	t = "hard" ;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(s,t) ;
	return 0 ;
}

