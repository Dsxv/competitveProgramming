#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 5 ;
int dp[N][N] ;
int mval[N][N] ;
int a[N] ;
int n ;

int solve(int i , int j){
	int turn = n + i - j ;
	if(i == j){
		return a[i] * turn + a[i] ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int x = turn * a[i] + solve(i + 1 , j) + mval[i][j];
	int y = turn * a[j] + solve(i , j - 1) + mval[i][j];
	return dp[i][j] = max(x , y) ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		cin >> n ;
		memset(dp , -1 , sizeof(dp)) ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < n ; i++){
			int mx = 0 ;
			for(int j = i ; j < n ; j++){
				mx = max(a[j] , mx) ;
				mval[i][j] = mx ;
			}
		}
		cout << solve(0 , n - 1) << '\n' ;
	}
	return 0 ;
}

