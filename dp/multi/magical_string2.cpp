#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 , mod = 1e9 + 7 ;
int dp[N][N] ;
int a[26];
int n ;
int solve(string& s , int i = 0 , int j = 0 , vector<bool> v = vector<bool>(26)){
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	v[s[i] - 'a'] = 1 ;
	for(int k = 0 ; k < 26 ; k++){
		if(v[k] && (i - j + 1) > a[k]){
			return INT_MIN ;
		}
	}
	int a = 0 , b = 0;
	if(i < n - 1){
		a = max(a , solve(s, i + 1 , i + 1 , vector<bool>(26)));
	}
	b = solve(s, i + 1 , j , v) ;
	return dp[i][j] = max({i-j+1,a,b}) ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	cin >> n ;
	string s ;
	cin >> s ;
	for(int i = 0 ; i < 26 ; i++) cin >> a[i] ;
	cout << solve(s) ;
	return 0 ;
}



