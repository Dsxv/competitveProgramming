#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		a[i] = abs(x) ;
	}
	sort(a,a+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++) {
		int x = (upper_bound(a+i,a+n,2*a[i]) - (a+i)) -1 ;
		ans += x ;
	}
	cout << ans ;
	return 0 ;
}

