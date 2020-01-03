#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int  t ;
	cin >> t ;
	while(t--){
		int a[3] ;
		cin >> a[0] >> a[1] >> a[2] ;
		sort(a,a+3) ;
		a[1] += a[0] ;
		cout << (a[2] - a[1] <= 1 ? "Yes\n" : "No\n" ) ;	
	}
	return 0 ;
}

