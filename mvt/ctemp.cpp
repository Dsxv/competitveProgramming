#include <bits/stdc++.h>
using namespace std ;


// a = IO  
// b = Io
// c = io
// d = iO
const int N = 105 ;
int dp[N][2][2][2][2] ;
int solve(string&s , int i = 0 , int a = 0 , int b = 0 , int c = 0 , int d = 0){
	if(a < 0 || b < 0 || c < 0 || d < 0) return INT_MIN ;
	if(a > 1 || b > 1 || c > 1 || d > 1) return INT_MIN ;
	if(i == s.size()) {
		if((a+b+c+d) == 0) return 0;
		else return INT_MIN ;
	}
	if(dp[i][a][b][c][d] != -1) return dp[i][a][b][c][d] ;
	if(s[i] == 'o'){
		return dp[i][a][b][c][d] = max(solve(s,i+1,a,b-1,c,d),solve(s,i+1,a,b,c-1,d)) ;
	}
	if(s[i] == 'O'){
		return dp[i][a][b][c][d] = max(solve(s,i+1,a-1,b,c,d)+1,solve(s,i+1,a,b,c,d-1)) ;
	}
	if(s[i] == 'I'){
		return dp[i][a][b][c][d] = max(solve(s,i+1,a+1,b,c,d),solve(s,i+1,a,b+1,c,d)) ;
	}
	if(s[i] == 'i'){
		return dp[i][a][b][c][d] = max(solve(s,i+1,a,b,c+1,d),solve(s,i+1,a,b,c,d+1)) ;
	}
	return -1 ;
}

int32_t main(){
	int x;
	cin >> x ;
	for(int t = 1 ; t <= x ; t++){
		string s ;
		cin >> s ;
		memset(dp,-1,sizeof(dp)) ;
		int count = solve(s) ;
		printf("Case #%d: %d\n",t,count) ;
	}
	return 0 ;
}

