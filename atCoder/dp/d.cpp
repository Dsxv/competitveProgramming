#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int tp = N ;
int dp[N] ;
int32_t main(){
	int n, val; 
	cin >> n >> val ;
	for(int i = 0 ; i < n ; i++){
		int w , v ; 
		cin >> w >> v ;
		for(int j = tp - w - 1 ; j >= 0 ; j--){
			dp[j+w] = max(dp[j+w] , dp[j] + v) ;
		}
	}
	cout << dp[val] ;
	return 0 ;
}

