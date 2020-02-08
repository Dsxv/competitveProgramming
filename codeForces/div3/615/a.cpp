#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a[3] , n ;
		cin >> a[0] >> a[1] >> a[2] >> n ;
		sort(a,a+3) ;
		n -= (2*a[2] - (a[0]+a[1])) ;
		if(n < 0 || abs(n)%3) cout << "NO\n" ;
		else cout << "YES\n" ;
	}
	return 0 ;
}

