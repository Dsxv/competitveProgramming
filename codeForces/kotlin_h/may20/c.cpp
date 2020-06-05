#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a = n/(k*k*k + k*k + k + 1) ;
		cout << a << " " << a*k << " " << a*k*k << " " << a*k*k*k << '\n' ;
	}
	return 0 ;
}

