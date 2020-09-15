#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[61][2][2][2] ;

int solve(int &x , int i = 60 , int j = 0 , int k = 0 , bool ok = 0){
	if(i == -1){
		return 1 ;
	}
	if(~dp[i][j][k][ok]) return dp[i][j][k][ok] ;
	int ans = 0 ;
	if((1LL<<i)&x){
		if(j == 0 && k == 1){
			ans = solve(x , i - 1 , 0 , j , ok|true) ;
		} else {
			ans = solve(x , i - 1 , 1 , j , ok) + solve(x , i - 1 , 0 , j , ok|true) ;
		}
	} else {
		if(ok && !(j == 0 && k == 1)) ans = solve(x , i - 1 , 1 , j , ok) ;
		ans += solve(x , i - 1 , 0 , j , ok) ;
	}
	return dp[i][j][k][ok] = ans ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int x ;
	cin >> x ;
	int unum = solve(x) - 1 ; // -1 because 0 is also included
	cout << x - unum;
	return 0 ;
}

