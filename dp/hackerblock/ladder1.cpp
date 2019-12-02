#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n+1] ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	int dp[n+1] = {0} ;
	dp[1] = 1 ;
	for(int i = 2 ; i <= n ; i++){
		if(!a[i]){
			for(int j = i - 1 ; j > 0 && j >= i - k ; j--)
				dp[i] = (dp[i] + dp[j]) %mod ;
		}
	}
	cout << dp[n] ;
	return 0 ;
}

