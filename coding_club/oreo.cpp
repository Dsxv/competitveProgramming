#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
int cnt[N] ;
int dp[1<<20][20] ;
const int mod = 998244353 ;

int modexp(int a , int n ){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int solve(int mask , int pos){
	if(pos == -1) return cnt[mask] ;
	if(~dp[mask][pos]) return dp[mask][pos] ;
	int ans = 0 ;
	if((1<<pos)&mask){
		ans = solve(mask^(1<<pos) , pos - 1) ;
	}
	ans += solve(mask , pos - 1) ;
	return dp[mask][pos] = ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	memset(dp , -1 , sizeof(dp)) ;
	int n , q;
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		cnt[x]++ ;
	}
	while(q--){
		int x ;
		cin >> x ;
		int val = solve(x , 19) ;
		cout << (val*modexp(n , mod - 2)) % mod << '\n' ;
	}
	return 0 ;
}

