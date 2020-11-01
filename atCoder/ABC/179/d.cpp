#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
int dp[N] ;
const int mod = 998244353 ;

int32_t main(){
	int n , k ;
	cin >> n >> k;
	pair<int,int> a[k] ;
	for(int i = 0 ; i < k ; i++){
		cin >> a[i].first >> a[i].second ;
	}
	dp[1] = 1 ;
	for(int i = 2 ; i <= n ; i++){
		for(int j = 0 ; j < k ; j++){
			int f = max(0LL , i - a[j].first) , s = max(0LL , i - a[j].second -1) ;
			dp[i] = (dp[i] + dp[f] - dp[s] + mod) % mod ;
		}
		dp[i] = (dp[i] + dp[i-1]) % mod ;
	}
	cout << ( dp[n] - dp[n-1] + mod ) % mod  ;
	return 0 ;
}

