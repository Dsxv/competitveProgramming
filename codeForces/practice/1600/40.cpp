#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , c , k;
		cin >> n >> c >> k; 
		int a[n+1] ;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i] ;
		}
		a[0] = 0 ;
		sort(a,a+n+1) ;
		int dp[n+1] = {};
		int ind = 0 ;
		for(int i = 1 ; i < k ; i++){
			dp[i] = dp[i-1] + a[i] ;
			if(dp[i] <= c) {
				ind = i ;
			}
		}
		for(int i = k ; i <= n ; i++){
				dp[i] = dp[i-k] + a[i] ;
				if(dp[i] <= c){
					ind = i ;
				}
		}
		cout << ind << endl ;
	}
	return 0 ;
}
