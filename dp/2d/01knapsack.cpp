#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ;

int dp[N][N] ;

int solve(pair<int,int>* ar , int n , int s , int i = 0 , int j = 0){
	if(j > s) return INT_MIN ;
	if(i == n) return 0;
	if(dp[i][j] != -1) return dp[i][j] ;
	int a = solve(ar , n , s , i+1 , j) ;
	int b = solve(ar,n, s, i+1, j+ar[i].first) ;
	return dp[i][j] = max(a,b+ar[i].second) ;
}

int32_t main(){
	int n , s ;
	cin >> n >> s ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i].first ;
	for(int i = 0 ; i < n ; i++) cin >> a[i].second ;
//	sort(a,a+n,[](pair<int,int> a , pair<int,int> b){ return a.second < b.second ; }) ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++) 
			dp[i][j] = -1 ;
	}
	cout << solve(a,n,s) ;	
	return 0 ;
}

