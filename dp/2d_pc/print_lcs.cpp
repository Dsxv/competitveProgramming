#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ;
const int M = 1e3 + 10 ;

int dp[N][M] ;

int lcs(string & a , string & b , int i = 0 , int j = 0 ){
	if(i == a.size() || j == b.size()) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(a[i] == b[j]) return dp[i][j] = lcs(a,b,i+1,j+1) + 1;
	else {
		return dp[i][j] = max(lcs(a,b,i,j+1),lcs(a,b,i+1,j)) ;
	}
}

string solve(string& a ,string & b , int i = 0 , int j = 0){
	if(i == a.size() || j == b.size()) return "";
	if(a[i] == b[j]) return a[i] + solve(a,b,i+1,j+1) ;
	if(dp[i][j+1] > dp[i+1][j]) return solve(a,b,i,j+1) ;
	else return solve(a,b,i+1,j) ;
}

int32_t main(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++) dp[i][j] = -1;
	}
	string a , b ;
	cin >> a >> b ;
	lcs(a,b) ;
	cout << solve(a,b) ;
	return 0 ;
}

