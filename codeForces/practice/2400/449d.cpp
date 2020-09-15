#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1 << 20 , mod = 1e9 + 7;
int dp[2][N] ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n;  cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int p ; cin >> p ;
		dp[1][p]++ ;
	}
	for(int i = 19 ; i >= 0 ; i--){
		int cur = i&1 ;
		for(int mask = 0 ; mask < N ; mask++){
			dp[cur^1][mask] = dp[cur][mask] ;
			if(mask&(1<<i)){
				dp[cur^1][mask^(1<<i)] += dp[cur][mask] ;
			}
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		if(__builtin_popcount(i)%2){
			ans -= modexp(2 , dp[1][i]) - 1 ;
		} else {
			ans += modexp(2 , dp[1][i]) - 1 ;
		}
		ans = (ans + mod) % mod ;
	}
	cout << ans ;
	return 0 ;
}

