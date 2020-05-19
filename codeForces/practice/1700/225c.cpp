#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int M = 1e3 + 10 ;

int dp[M][2] ;
int n , m , x , y ;
int a[M] ;

int sum(int j , int l , int r){
	if(r >= m) return INT_MAX ; 
	if(l == 0){
		int sum = a[r] ;
		if(j) sum = (r-l+1)*n - sum ;
		return sum ;
	} else {
		int sum = a[r] - a[l-1] ;
		if(j) sum = (r-l+1)*n - sum ;
		return sum ;
	}
}

int solve(int i , int j){
	if(i == m){
		return 0 ;
	}
	if(i > m){
		return INT_MAX ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	dp[i][j] = INT_MAX ;
	for(int k = i + x ; k <= i + y ; k++){
		dp[i][j] = min(dp[i][j] , solve(k,!j) + sum(j,i,k-1)) ;
	}
	return dp[i][j] ;
}
int32_t main(){
	cin >> n >> m >> x >> y ;
	memset(dp,-1,sizeof(dp)) ;
	string s[n] ;
	for(int i = 0 ; i < n ; i++) cin >> s[i] ;
	for(int j = 0 ; j < m ; j++){
		for(int i = 0 ; i < n ; i++) a[j] += s[i][j] == '.' ;
		if(j) a[j] += a[j-1] ;
	}
	cout << min(solve(0,0) , solve(0,1)) << '\n' ;
	return 0 ;
}

