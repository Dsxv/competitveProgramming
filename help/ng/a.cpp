#include <bits/stdc++.h>
using namespace std ;

#define int long long
constexpr int mod = 1e9 + 7 ;
const int N = 1e4 + 5 ;
int dp[N][21] ;

int n , x , y ;

int solve(int i = 0 , int px = 0 , bool taken = 1){
	if(i == n){
		return px == 0 ;
	}
	if(~dp[i][px]) return dp[i][px] ;
	int ans = 0 ;
	for(int j = taken ; j < 10 ; j++){
		ans = (ans + solve( i + 1 , (px*10 + j) % x) , 0) % mod ;
	}
	return dp[i][px] = ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> x >> y ;
		x = (x*y) / __gcd(x,y) ;
		memset(dp , -1 , sizeof(dp)) ;
		cout << solve() << '\n' ;
	}
	return 0 ;
}

