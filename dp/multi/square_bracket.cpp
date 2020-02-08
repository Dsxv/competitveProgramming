#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<bool> ks ;
const int N = 55 , mod = 1e9 + 7 ;
int n , k ;

int dp[N][N]; // index , total elements , current element

int solve(int i = 0 , int j = 0){
	if(i == n){
		return j == (i-j) ;
	}
	if((i-j) > j) {
		return 0 ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	int ans = 0 ;
	if(ks[i]) {
		ans = solve(i+1,j+1) ;
	} else {
		ans = (solve(i+1,j+1) + solve(i+1,j)) % mod;
	}
	return dp[i][j] = ans ;
}
	

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> k ;
		n *= 2 ;
		ks.clear() ;
		ks.resize(n) ;
		memset(dp,-1,sizeof(dp)) ;
		for(int i = 0 ; i < k ; i++) {
			int x ; cin >> x ;
			ks[x-1] = 1 ;
		}
		cout << solve() << endl;
	}
	return 0 ;
}

