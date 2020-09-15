#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >>  n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	int ans = 0 ;
	for(int l = 0 , r = 0 ; l < n ; l++){
		while(r < n && a[r] - a[l] <= 5) r++ ;
		ans = max(ans , r - l) ;
	}
	cout << ans ;
	return 0 ;
}

