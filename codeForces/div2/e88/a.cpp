#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m , k ;
		cin >> n >> m >> k ;
		int f = min(n/k,m) ;
		int rem = m - f ;
		cout << f - ((rem + k-2)/(k-1)) << endl ;
	}
	return 0 ;
}

