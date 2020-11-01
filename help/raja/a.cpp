#include <bits/stdc++.h>
using namespace std ;

#define int long long
int primes[10] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29} ;
int dp[2][105][1 << 10] ;
constexpr int mod = 1e9 + 7 ;

int getMask(int n){
	int ans = 0 ;
	if(n == 0) return ans ;
	for(int i = 0 ; i < 10 ; i++){
		int cnt = 0 ;
		while(n % primes[i] == 0) {
			n /= primes[i] ;
			cnt++ ;
		}
		ans |= (cnt & 1) << i ;
	}
	return ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int mask[35] = {} ;
	for(int i = 0 ; i < 35 ; i++){
		mask[i] = getMask(i) ;
	}
	while(t--){
		int n , m ;
		cin >> n >> m ;
		memset(dp , 0 , sizeof(dp)) ;
		int a[n][m] ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++) cin >> a[i][j] ;
		}
		
		for(int i = n - 1 ; i >= 0 ; i--){
			int cur = i % 2 , prev = (i + 1) % 2 ;
			for(int j = m - 1 ; j >= 0 ; j--){
				if(i == n - 1 && j == m - 1){
					dp[cur][j][mask[a[i][j]]]++ ;
					continue ;
				}
				for(int k = 0 ; k < (1 << 10) ; k++){
					dp[cur][j][k] = 0 ;
				}
				int x = mask[a[i][j]] ;
				for(int k = 0 ; k < (1 << 10) ; k++){
					dp[cur][j][k] += dp[cur][j+1][k ^ x] ;
					dp[cur][j][k] += dp[prev][j][k ^ x] ;
					dp[cur][j][k] %= mod ;
				}
			}
		}
		cout << dp[0][0][0] << '\n' ;
	}
	return 0 ;
}

