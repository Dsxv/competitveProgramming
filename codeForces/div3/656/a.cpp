#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a[3] ;
		cin >> a[0] >> a[1] >> a[2] ;
		sort(a,a+3) ;
		if(a[1] == a[2]){
			cout << "YES\n" ;
			cout << a[1] << " " << a[0] << " " << 1 << '\n' ;
		} else {
			cout << "NO\n" ;
		}
	}
	return 0 ;
}

