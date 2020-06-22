#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e3 + 10 ;
int dp[N][N] ;

int solve(string&a , string&b , int i = 0 , int j = 0){
	if(i == a.size()){
		return abs((int)b.size() - j) ;
	}
	if(j == b.size()){
		return abs((int)a.size() - i) ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	if(a[i] == b[j]){
		return dp[i][j] = solve(a,b,i+1,j+1) ;
	} else {
		int x = solve(a,b,i+1,j) , y = solve(a,b,i,j+1) , z = solve(a,b,i+1,j+1) ;
		return dp[i][j] = min({x,y,z}) + 1 ;
	}
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	string a,b ;
	cin >> a >> b ;
	cout << solve(a,b) ;
	return 0 ;
}

