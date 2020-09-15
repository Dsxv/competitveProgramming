#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
const int mod = 1e9 + 7 ;
int dp[N][27] ;

int solve(int * a , int n , int i = 0 , int j = 0){
	if(j == 26){
		return 1 ;
	}
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	dp[i][j] = solve(a, n , i + 1 , j) ;
	if(a[i] == (j+1)){
		dp[i][j] = (dp[i][j] + solve(a , n , i + 1 , a[i])) % mod ;
	}
	return dp[i][j] ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp , -1 , sizeof(dp)) ;
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			char ch ;
			cin >> ch ;
			a[i] = (ch - 'a') + 1 ;
		}
		cout << solve(a,n) << '\n' ;
	}
	return 0 ;
}

