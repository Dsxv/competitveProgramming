#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 3e3 + 10 ;
int dp[N][N] ;

int solve(string &a , string &b , int i = 0 , int j = 0){
	if(i == a.size() || j == b.size()) return 0 ;
	if(~dp[i][j]) return dp[i][j] ;
	if(a[i] == b[j]) {
		return dp[i][j] = 1 + solve(a , b , i + 1 , j + 1) ;
	}
	else {
		return dp[i][j] = max(solve(a , b , i + 1 , j ) , solve(a , b , i , j + 1)) ;
	}
}	

void getval(string &a , string &b , string& ans ,  int i = 0 , int j = 0){
	if(i == a.size() || j == b.size()) return ;
	if(a[i] == b[j]) {
		ans += a[i] ;
		getval(a , b , ans , i + 1 , j + 1) ;
	} else {
		if(solve(a,b,i+1,j) > solve(a,b,i,j+1)){
			getval(a,b,ans,i+1,j) ;
		} else {
			getval(a,b,ans,i,j+1) ;
		}
	}
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	string a , b ;
	cin >> a >> b ;
	solve(a,b) ;
	string ans = "" ;
	getval(a,b,ans) ;
	cout << ans ;
	return 0 ;
}

