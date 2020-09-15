#include <bits/stdc++.h>
using namespace std ;

#define int long long
int dp[1<<20][20] ;
const int N = 1 << 20 , mod = 1e9 + 7 ;
int cnt[N+10] ;

int solve(int mask , int pos){
	if(pos == -1) return cnt[mask] ;
	if(~dp[mask][pos]) return dp[mask][pos] ;
	int ans = 0 ;
	if((1<<pos)&mask){
		ans += solve(mask^(1<<pos) , pos - 1) ;
	}
	ans += solve(mask , pos - 1) ;
	return dp[mask][pos] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] , cnt[a[i]]++ ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans += solve(((1<<20) - 1)^a[i] , 19) ;
	}
	cout << ans ;
	return 0 ;
}

