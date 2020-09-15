#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
constexpr int mod = 1e9 + 7 ;
int dp[N][2][2] ;
int n; 

int solve(int i = 0 , bool a = 0 , bool b = 0){
	if(i == n){
		return a & b ;
	}
	if(~dp[i][a][b]) return dp[i][a][b] ;
	int ans = 0 ;
	for(int j = 0 ; j < 10 ; j++){
		ans = (ans + solve(i + 1 , a | (j == 0) , b | (j == 9)))  % mod ;
	}
	return dp[i][a][b] = ans ;
}

int32_t main(){
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	cout << solve() ;
	return 0 ;
}

