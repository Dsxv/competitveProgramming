#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] >> b[i] ;
		}
		int mx1 = INT_MIN , mx2 = INT_MIN ;
		for(int i = 0 ; i < n ; i++){
			mx1 = max(mx1 , a[i] + b[i]) ;
			mx2 = max(mx2 , a[i] - b[i]) ;
		}
		int ans = INT_MIN ;
		for(int i = 0 ; i < n ; i++){
			ans = max(ans , a[i] + b[i] + mx2) ;
			ans = max(ans , a[i] - b[i] + mx1) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

