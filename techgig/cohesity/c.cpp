#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
int dp[N][105] ;

int solve(int* a, int n , int i = 1 , int j = 0 ,int s = 0){
	if(i == n){
		return 0; 
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	int ans = 0 ;
	for(int x = 1 ; x <= a[i] ; x++){
		ans = max(ans,abs(x-j) + solve(a,n,i+1,x)) ;
	}
	return	dp[i][j] = ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < 105 ; j++){
				dp[i][j] = -1 ;
			}
		}
		cout << solve(a,n) << '\n';
	}

	return 0 ;
}

