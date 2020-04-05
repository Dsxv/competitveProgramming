#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[5005] ;

int solve(string&s , int i = 0){
	if(i >= ((int)s.size() - 1)){
		return i == s.size() || s[i]-'0' ;
	}
	if(~dp[i]) return dp[i] ;
	int x = 0 , y = 0 ;
	if(s[i]-'0' == 0) return 0 ;
	x = solve(s,i+1) ;
	if((s[i]-'0')*10 + (s[i+1]-'0') <= 26)
		y = solve(s,i+2) ;
	return dp[i] = x+y ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp,-1,sizeof(dp)) ;
		string s ;
		cin >> s ;
		cout << solve(s) << endl ;
	}
	return 0 ;
}

