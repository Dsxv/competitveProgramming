#include <bits/stdc++.h>
using namespace std ;

const int N = 1 << 24 ;
int dp[2][N] ;

int createMask(string s){
	int ans = 0 ;
	for(auto i : s) ans |= 1 << (i - 'a') ;
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	string s ;
	for(int i = 0 ; i < n ; i++){
		cin >> s ;
		int x = createMask(s) ;
		dp[1][N-1]++ ; dp[1][(N-1)^x]-- ;
	}
	for(int i = 23 ; i >= 0 ; i--){
		int cur = i%2 ;
		for(int mask = 0 ; mask < N ; mask++){
			dp[cur^1][mask] = dp[cur][mask] ;
			if(mask&(1<<i)){
				dp[cur^1][mask^(1<<i)] += dp[cur][mask] ;
			}
		}
	}

	int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		ans ^= dp[1][i]*dp[1][i] ;
	}
	cout << ans ;
	return 0 ;
}
