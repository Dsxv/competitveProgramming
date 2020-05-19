#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e5 + 10 ;

int32_t main(){
	int t; 
	cin >> t ;
	int dp[N] ;
	for(int i = 3 ; i < N ; i++){
		if(i&1){
			dp[i] = dp[i-2] + (i-1)*4*(i/2) ;
		}
	}
	while(t--){
		int n ;
		cin >> n ;
		cout << dp[n] << '\n' ;
	}
	return 0 ;
}

