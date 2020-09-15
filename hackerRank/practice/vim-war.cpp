#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
int dp[1 << 20][20] ;
int cnt[1 << 20] ;
int n , m ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int getMask(string s){
	int ans = 0 ;
	for(int i = 0 ; i < m ; i++) {
		if(s[i] - '0') {
			ans |= 1 << i ;
		}
	}
	return ans ;
}

int solve(int mask , int pos){
	if(pos == -1){
		return cnt[mask] ;
	}
	if(~dp[mask][pos]) return dp[mask][pos] ;
	int ans = 0 ;
	if(mask&(1<<pos)){
		ans = solve(mask ^ ( 1 << pos) , pos - 1) ;
	}
	ans = (ans + solve(mask , pos - 1)) % mod ;
	return dp[mask][pos] = ans ;
}


int32_t main(){
	cin >> n >> m ;
	memset(dp , -1 , sizeof(dp))  ;
	for(int i = 0 ; i < n ; i++){
		string s ; cin >> s ;
		cnt[getMask(s)]++ ;
	}
	string t ; cin >> t ;
	int mask = getMask(t) ;
	int ans = 0 ;
	for(int i = 0 ; i <= mask ; i++){
		if((i&mask) != i) continue ;
		int val = (modexp(2 , solve(i , m - 1)) - 1 + mod ) % mod ;
		if((__builtin_popcount(mask) - __builtin_popcount(i)) % 2){
			ans -= val ;
		} else {
			ans += val ;
		}
		ans = (ans + mod) % mod ;
	}
	cout << ans ;
	return 0 ;
}

