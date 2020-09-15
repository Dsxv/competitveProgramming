#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 3e5 + 10 ;
int dp[N][6][2] ;
int n , k , z ;

int solve(int* a , int i = 0 , int j = 0 , bool prev = false){
	if(i + 2*j == k){
		return a[i] ;
	}
	if(~dp[i][j][prev]) return dp[i][j][prev] ;
	int v1 = 0 ;
	if(i && !prev && j < z){
		v1 = solve(a , i - 1 , j + 1 , true) ;
	}
	int v2 = solve(a , i + 1 , j , false) ;
	return dp[i][j][prev] = max(v1 , v2) + a[i] ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> k >> z;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < 6 ; j++){
				for(int k = 0 ; k < 2 ; k++) dp[i][j][k] = -1 ;
			}
		}
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		cout << solve(a) << '\n' ;
	}
	return 0 ;
}

