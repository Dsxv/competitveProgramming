#include <bits/stdc++.h>
using namespace std ;

#define int long long

double dp[100][100][100] ;

int a , b , c ;


int32_t main(){
	cin >> a >> b >> c ;
	memset(dp , -1 , sizeof(dp)) ;
	solve() ;
	return 0 ;
}

