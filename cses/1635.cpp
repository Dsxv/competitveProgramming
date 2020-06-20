#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 , mod = 1e9 + 7 ;
int dp[N] ;

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	dp[0] = 1 ;
	for(int i = 1 ; i <= x ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i - a[j] >= 0){
				dp[i] = (dp[i] + dp[i-a[j]]) % mod ;
			}
		}
	}
	cout << dp[x] ;
	return 0 ;
}

