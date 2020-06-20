#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 + 10 ;
int dp[N] ;
int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 1 ; i < N ; i++) dp[i] = INT_MAX ;
	for(int i = 1 ; i < 10 ; i++) dp[i] = 1 ;

	for(int j = 10 ; j <= n ; j++){
		vector<int> v ;
		int x = j ;
		while(x) {
			v.push_back(x%10) ;
			x /= 10 ;
		}
		for(auto i : v){
			dp[j] = min(dp[j] , 1 + dp[j-i]) ;
		}
	}
	cout << dp[n] ;
	return 0 ;
}

