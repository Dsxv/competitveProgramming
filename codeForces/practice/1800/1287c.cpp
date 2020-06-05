#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 105 ;
int dp[N][N][N][2] ;
int n , odd , even ;
int a[N] ;

int solve(int i , int j , int k  , bool prev ){
	if(j > odd || k > even) return INT_MAX ;
	if(i == n){
		if(j == odd && k == even) return 0 ;
		else return INT_MAX ;
	}
	if(~dp[i][j][k][prev]) return dp[i][j][k][prev] ;
	if(a[i]){
		return dp[i][j][k][prev] = solve(i+1,j,k,a[i]&1) + (prev^(a[i]&1)) ;
	}
	return dp[i][j][k][prev] = min(solve(i+1,j+1,k,1) + (prev == 0), solve(i+1,j,k+1,0) + prev) ;
}



int32_t main(){
	cin >> n ;
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		if(a[i]) {
			odd += a[i]&1 ;
			even += a[i]%2 == 0 ;
		}
	}
	odd = (n+1)/2 - odd ;
	even = n/2 - even ;
	cout << min(solve(0,0,0,1) , solve(0,0,0,0)) ;
	return 0 ;
}

