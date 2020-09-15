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
		dp[1][(1<<24)-1]++ ; dp[1][((1<<24)-1)^x]-- ;
	}
	for(int i = 23 ; i >= 0 ; i--){
		int k = (i + 1) % 2 ;
		for(int j = 0 ; j < (1 << 24) ; j++){
			dp[k][j] = dp[i%2][j] ;
		}
		for(int j = 0 ; j < (1 << 24) ; j++){
			if(j&(1<<i)){
				dp[k][(1<<i)^j] += dp[i%2][j] ;
			}
		}
	}
	int ans = 0 ;
	for(int i = 0 ; i < (1 << 24) ; i++){
		ans ^= dp[1][i]*dp[1][i] ;
	}
	cout << ans ;
	return 0 ;
}

