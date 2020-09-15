#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int ans = 0 ;
		for(int i = n - 1 ; i >= 1 ; i--){
			ans += max(0LL , a[i-1] - a[i]) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

