#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 ;
int dp[N][N][2][2] ;
int n , m ;

int solve(string &a , string &b , int i = 0 , int j = 0 , bool x = 0 , bool y = 0){
	if(i == n || j == m){
		if(x || y) return INT_MIN ;
		return 0 ;
	}
	int ans = INT_MIN ;
	if(x == 0 && y == 0){
		ans = max({ans , solve(a,b,i+1,j,0,0) , solve(a,b,i,j+1,0,0)}) ;
		ans = max({ans , solve(a,b,i,j,1,0) + i , solve(a,b,i,j,0,1) + j}) ;
	} else if(x){
		ans = max({ans , solve(a,b,i,j+1,1,0) , solve(a,b,i,j,1,1) + j}) ;
	} else if(y){
		ans = max({ans , solve(a,b,i+1,j,0,1) , solve(a,b,i,j,1,1) + i}) ;
	} else {
		return -(i + j) ;
		if(a[i] == b[j]){
			int val = 4 + solve(a,b,
		} else {



int32_t main(){
	cin >> n >> m ;
	memset(dp , -1 , sizeof(dp)) ;
	string a , b ;
	cin >> a >> b ;
	cout << solve(a , b) ;
	return 0 ;
}

