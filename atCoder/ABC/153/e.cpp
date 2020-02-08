#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int H = 1e4 + 10 ;
int dp[H];

int solve(pair<int,int>* a , int n , int h){
	if(h <= 0) return 0 ;
	if(dp[h] != -1) return dp[h] ;
	int ans = INT_MAX ;
	for(int i = 0 ; i < n ; i++){
		ans = min(ans, solve(a , n , h - a[i].first) + a[i].second) ;
	}
	return dp[h] = ans ;
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	int h, n ;
	cin >> h >> n ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first >> a[i].second ;
	}
	cout << solve(a,n,h) ;
	return 0 ;
}

