#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x , y ; cin >> x >> y ;
	bitset<100> a(x) , b(y) , c(0) ;
	bool ok = false ;
	for(int i = 99 ; i >= 0 ; i--){
		ok += a[i] != b[i] ;
		c[i] = ok ;
	}
	cout << c.to_ullong() ;
	return 0 ;
}

