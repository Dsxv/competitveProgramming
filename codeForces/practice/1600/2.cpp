#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;
int tree(int k , int n){
	int dp[105] = {} ;
	for(int i = 1 ; i <= n ; i++){
		if(i <= k) dp[i] = 1 ;
		for(int j = i - 1 ; j >= max(1LL,i-k) ; j--){
			dp[i]  = (dp[i] + dp[j]) % mod ;
		}
	}
	return dp[n];
}


int32_t main(){
	int n , k , d ;
	cin >> n >> k >> d ;
	cout << (tree(k,n) - tree(d-1,n) + mod) % mod ;
	return 0 ;
}

