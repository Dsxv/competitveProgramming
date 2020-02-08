#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 40 ;
int dp[N][N][N][2] ;
int x , y , l;
int solve(bitset<40>& c, int i , int ca , int cb , bool carry){
	if(i == l){
			return (ca == x && cb == y && carry == 0) ;
	}
	if(ca > x || cb > y) return 0 ;
	if(dp[i][ca][cb][carry] != -1) return dp[i][ca][cb][carry] ;
	int ans = 0 ;
	if(c[i]){
		if(carry){
			ans = solve(c,i+1,ca,cb,0) + solve(c,i+1,ca+1,cb+1,1) ;
		} else {
			ans = solve(c,i+1,ca+1,cb,0) + solve(c,i+1,ca,cb+1,0) ;
		}
	} else {
		if(carry){
			ans = solve(c,i+1,ca+1,cb,1) + solve(c,i+1,ca,cb+1,1) ;
		} else {
			ans = solve(c,i+1,ca,cb,0) + solve(c,i+1,ca+1,cb+1,1) ;
		}
	}
	return dp[i][ca][cb][carry] = ans ;
}		

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b , c ;
		cin >> a >> b >> c ;
		x = __builtin_popcount(a) ;
		y = __builtin_popcount(b) ;
		memset(dp,-1,sizeof(dp)) ;
		bitset<40> bc(c) ;
		for(int i = 0 ; i < 32 ; i++) {
			if(bc[i]) l = i+1 ;
		}
		cout << solve(bc,0,0,0,0) << endl ;
	}
	return 0 ;
}

