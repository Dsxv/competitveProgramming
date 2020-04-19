#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int dp[N][2][3] ;
// 2 ; j = 0 means prev was 0 , j = 1 means prev was 1
// 3 : k = 0 means no flip till now, k == 1 flip is going on , k == 2 means flip happened
int n ;
int solve(int* a , int i , int j , int k){
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	if(k == 0){
		if(j != a[i]) {
			return dp[i][j][k] = max(solve(a,i+1,a[i],k) , solve(a,i+1,a[i],k+1)) + 1 ;
		} else {
			return dp[i][j][k] = solve(a,i+1,j,k) ;
		}
	}
	if(k == 1){
		if(j == a[i]) {
			return dp[i][j][k] = max(solve(a,i+1,!a[i],k) , solve(a,i+1,!a[i],k+1)) + 1 ;
		} else {
			return dp[i][j][k] = solve(a,i+1,j,k) ;
		}
	}
	if(k == 2){
		if(j != a[i]){
			return dp[i][j][k] = solve(a,i+1,a[i],k) + 1 ;
		} else {
			return dp[i][j][k] = solve(a,i+1,j,k) ;
		}
	}
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n ;
	int a[n] ;
	string s ; cin >> s ;
	for(int i = 0 ; i < n ; i++) a[i] = s[i] == '1' ;
	int ans = 0 ;
	for(int j = 0 ; j < 2 ; j++){
		for(int k = 0 ; k < 2 ; k++){
			ans = max(ans,solve(a,0,j,k)) ;
		}
	}
	cout << ans ;
	return 0 ;
}

