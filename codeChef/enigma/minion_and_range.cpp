#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n+1] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i+1] ;
		}
		int dp[n+1] = {0} ;
		for(int i = 1 ; i <= n ; i++){
			dp[i] = dp[i-1] + (a[i]%2 == 0) ;
		}
		int q ;
		cin >> q ;
		while(q--){
			int l , r ;
			cin >> l >> r ;
			int k = dp[r] - dp[l-1] ;
			if(k){
				cout << "EVEN\n" ;
			} else {
				cout << "ODD\n" ;
			}
		}
	}
	return 0 ;
}

