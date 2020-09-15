#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int l , r,  d ;
	cin >> l >> r >> d ;
	cout << r / d - l / d + (l%d == 0) ;
	return 0 ;
}

