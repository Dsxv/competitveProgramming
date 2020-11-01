#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	double val = 0 ;
	int ans = 0 , ans2 = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans += abs(a[i]) ;
		ans2 = max(ans2 , abs(a[i])) ;
		val += a[i]*a[i] ;
	}
	cout << ans << '\n' ;
	cout << fixed << setprecision(14) << sqrt(val) << endl ;
	cout << ans2 ;
	return 0 ;
}

