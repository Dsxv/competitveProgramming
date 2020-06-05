#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 18 ;
int g[N][N] ;
int dp[1<<N][N] ;
int n , m , k ;

int solve(int * a , int mask , int j){
	if(__builtin_popcount(mask) == m){
		return 0 ;
	}
	if(~dp[mask][j]) return dp[mask][j] ;
	for(int i = 0 ; i < n ; i++){
		if((1<<i)&mask) continue ;
		dp[mask][j] = max(dp[mask][j] , solve(a, mask | (1<<i) , i) + g[j][i] + a[i]) ;
	}
	return dp[mask][j] ;
}


int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n >> m >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < k ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		cin >> g[f][s] ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans = max(ans , solve(a,0|(1<<i),i) + a[i]) ;
	}
	cout << ans ;
	return 0 ;
}

