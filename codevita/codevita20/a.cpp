#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	int a[n] ; 
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	long double ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		ans += 1.0 / (long double) i ;
	}
	cout << fixed << setprecision(6) << ans ;
	return 0 ;
}

