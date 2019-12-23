#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2005 , M = 2005 ;

int dp[N][M][10] ;

int n , m , K ;

int solve(int* a , int* b , int i = 0 , int j = 0 , int k = 0){
	if(k > K) return INT_MIN ;
	if(i == n || j == m) return 0;
	if(dp[i][j][k] != -1) return dp[i][j][k] ;
	if(a[i] == b[j]) return dp[i][j][k] = solve(a,b,i+1,j+1,k) + 1;
	return dp[i][j][k] = max({solve(a,b,i+1,j+1,k+1) + 1,
						solve(a,b,i,j+1,k) , solve(a,b,i+1,j,k)}) ;
}


int32_t main(){
	cin >> n >> m >> K;
	int a[n] , b[m] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < m ; i++) cin >> b[i] ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			for(int k = 0 ; k <= K ; k++) dp[i][j][k] = -1 ;
		}
	}
	cout << solve(a,b) ;
	return 0 ;
}

