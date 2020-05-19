#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n+1] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
		int dp[n+1] = {} ;
		for(int i = n ; i >= 1 ; i--){
			dp[i] = 1 ;
			for(int j =  2*i ; j <= n ; j += i){
				if(a[i] < a[j]) dp[i] = max(dp[i] , 1 + dp[j]) ;
			}
		}
		cout << *max_element(dp+1,dp+n+1) << '\n';
	}
	return 0 ;
}

