#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 3e3 + 10 ;
int dp[N][N][2] ;

int solve(int *a , int i , int j , int k = 0){
	if(i >= j) return 0 ;
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(!k){
		int x = max(solve(a , i + 1 , j , 0) , solve(a , i , j - 1 , 0)) ;
		return dp[i][j][k] = max({ 0LL , x , solve(a , i + 1 , j - 1 , 1) + a[i]*a[j]}) ;
	} else {
		return dp[i][j][k] = max(0LL , a[i]*a[j] + solve(a , i + 1 , j - 1 , 1) ) ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(a , 0 , n - 1) ;
	return 0 ;
}

