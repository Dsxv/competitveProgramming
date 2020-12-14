#include <bits/stdc++.h>
using namespace std ;

#define int long long

int a[55] , b[55] ;
int dp[55][6005] ;
const int inf = 1e15 ;
int n , k , d;

int solve(int i , int p){
	if(i == (n + 1)){
		return 0 ;
	}
	if(~dp[i][p]) return dp[i][p] ;
	int dis = a[i+1] - a[i] ;
	int x = solve(i + 1 , max(0LL , p - dis)) + max(0LL , (dis - p)) * 5 + min(p , dis) ;
	int tp = p + b[i] ;
	int y = solve(i + 1 , max(0LL , tp - dis)) + max(0LL , (dis - tp)) * 5 + min(tp , dis) + k;
	return dp[i][p] = min(x , y) ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int p ; 
	cin >> n >> d >> p >> k ;
	a[0] = b[0] = 0 ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int i = 1 ; i <= n ; i++) cin >> b[i] ;
	a[n+1] = d ; b[n+1] = 0 ;
	cout << solve(0,p) ;
	return 0 ;
}

