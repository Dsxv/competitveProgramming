#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 , mod = 1e9 + 7 ;
int dp[N][105] ;
int n , m ;
int solve(int * a , int i = 0, int j = 0){
	if(i && (j < 1 || j > m)){
		return 0 ;
	}
	if(i == n){
		return 1 ;
	}
	if(a[i]){
		if(abs(a[i]-j) <= 1 || !i){
			return dp[i][j] = solve(a,i+1,a[i]) ;
		} else {
			return 0 ;
		}
	}
	if(~dp[i][j]) return dp[i][j] ;
	int ans = 0 ;
	if(!j){
		for(int k = 1 ; k <= m ; k++){
			ans = (ans + solve(a,i+1,k)) % mod ;
		}
	} else {
		ans = (solve(a,i+1,j-1) + solve(a,i+1,j) + solve(a,i+1,j+1)) % mod ;
	}
	return dp[i][j] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	cout << solve(a) ;
	return 0 ;
}

