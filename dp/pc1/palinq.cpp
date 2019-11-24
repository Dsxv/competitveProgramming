#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 5 ; 

int dp[N][N] ;

int32_t main(){
	int n , m;
	string s ;
	cin >> n >> s ;
	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = 0 ; j < n ; j++){
			if(i >= j) dp[i][j] = 1 ;
			else dp[i][j] = dp[i+1][j-1]*(s[i] == s[j]) ;
		}
	}
	cin >> m ;
	while(m--){
		int l , r ;
		cin >> l >> r ;
		l-- , r-- ;
		cout << (dp[l][r]?"YES\n":"NO\n") ;
	}
	return 0 ;
}

