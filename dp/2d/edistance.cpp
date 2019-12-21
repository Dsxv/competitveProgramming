#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 5 ;

int dp[N][N] ;

int solve(string s1 , string s2 , int i = 0 , int j = 0){
	if(i == s1.size() || j == s2.size()) {
		int a = s1.size() , b = s2.size() ;
		return abs(a+j-b-i) ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	if(s1[i] == s2[j]) return dp[i][j] = solve(s1,s2,i+1,j+1) ;
	int del1 = 1 + solve(s1,s2,i+1,j) ;
	int del2 = 1 + solve(s1,s2,i,j+1) ;
	int rep = 1 + solve(s1,s2,i+1,j+1) ;
	return dp[i][j] = min({del1,del2,rep}) ;
}

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	for(int i = 0 ; i < a.size() ; i++){
		for(int j = 0 ; j < b.size() ; j++) dp[i][j] = -1 ;
	}
	cout << solve(a,b) ;
	return 0 ;
}

