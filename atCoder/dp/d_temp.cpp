#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , w ;
	cin >> n >> w ;
	int dp[w+1] = {} ;
	for(int i = 0 ; i < n ; i++){
		int x , y ; 
		cin >> x >> y ;
		for(int j = w - x ; j >= 0 ; j--){
			dp[j+x] = max(dp[j+x] , dp[j] + y) ;
		}
	}
	cout << dp[w] ;
	return 0 ;
}

