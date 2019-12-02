#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 205 ;

int dp[N][N][N] ;

int solve(string a , string b , string c , int i = 0 , int j = 0 , int k = 0){
	if(i == a.size() || j == b.size() || k == c.size()) return 0 ;
	if(dp[i][j][k] != -1) return dp[i][j][k] ;

	if(a[i] == b[j] && b[j] == c[k]) return dp[i][j][k] = 1 + solve(a,b,c,i+1,j+1,k+1) ;
	return dp[i][j][k] =  
		max({solve(a,b,c,i+1,j,k),solve(a,b,c,i,j+1,k),solve(a,b,c,i,j,k+1)}) ;
}

int32_t main(){
	string a , b , c ;
	cin >> a >> b >> c ;
	for(int i = 0 ; i <= a.size() ; i++){
		for(int j = 0 ; j <= b.size() ; j++){
			for(int k = 0 ; k <= c.size() ; k++) dp[i][j][k] = -1 ;
		}
	}
	cout << solve(a,b,c) ;
	return 0 ;
}

