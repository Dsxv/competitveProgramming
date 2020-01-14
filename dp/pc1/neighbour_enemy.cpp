#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 2 ;
int a[N] , dp[N];
int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		a[x]++ ;
	}
	dp[1] = a[1] ;
	dp[2] = max(a[1],2*a[2]) ;
	for(int i = 3 ; i < N ; i++){
		dp[i] = max(dp[i-1] , dp[i-2] + i*a[i]) ;
	}
	cout << dp[N-1] ;
	return 0 ;
}

