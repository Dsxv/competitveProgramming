#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a ;
		cin >> a ;
		cout << (1LL<<(__builtin_popcount(a))) << '\n' ;
	}
	return 0 ;
}

