#include <bits/stdc++.h>
using namespace std ;

#define int long long

double dp[3003][3003] ;
int vis[3003][3003] ;
double p[3003] ;
int n ;
double solve(int i , int j ){
	if(i == n){
		if(j) return 0;
		return 1 ;
	}
	if(vis[i][j]) return dp[i][j] ;
	vis[i][j] = 1 ;
	return dp[i][j] = solve(i + 1, j - 1)*p[i] + solve(i + 1 , j)*(1 - p[i]) ;
}

int32_t main(){
	cin >> n ;
	for(int i = 0 ; i < n ; i++) cin >> p[i] ;
	double ans = 0;
	for(int i = n / 2 + 1 ; i <= n ; i++){
		ans += solve(0 , i) ;
	}
	cout << fixed << setprecision(10) << ans ;
	return 0 ;
}

