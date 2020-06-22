#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;
int dp[2][N] ;

int32_t main(){
	int n , m;
	cin >> n >> m;
	int a[n] , b[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> b[i] ;
	}
	// first index is product , 2nd is value
	for(int i = 0 ; i < n ; i++){
		bool x = i&1 ;
		for(int j = 1 ; j <= m ; j++){
			if(i) {
				dp[x][j] = dp[1-x][j] ;
			}
			if(j >= a[i]){
				int val = b[i] ;
				if(i > 0) val += dp[1-x][j-a[i]] ;
				dp[x][j] = max(dp[x][j] , val) ;
			}
		}
	}
	cout << dp[(n-1)&1][m] ;		
	return 0 ;
}

