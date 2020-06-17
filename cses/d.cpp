#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int mx = 0 ;
	int ans = 0 ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		ans += max(0LL , mx - a[i]) ;
		mx = max(a[i] , mx) ;
	}
	cout << ans ;
	return 0 ;
}

