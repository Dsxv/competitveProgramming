#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int id = upper_bound(a,a+n,a[i]+5) - (a+i) ;
		ans = max(ans , id) ;
	}
	cout << ans ;
	return 0 ;
}

