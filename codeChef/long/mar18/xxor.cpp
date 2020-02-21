#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int n ;
	cin >> n;
	int a[n+1] = {};
	for(int i = 1 ; i <= n ; i++){
		int x ; 
		cin >>  x ;
		a[i] = a[i-1]^x ;
	}
	int q ;
	cin >>  q;
	while(q--){
		int l , r ;
		cin >> l >> r ;
		int k = (a[r]^a[l-1]) ;
		bitset<32> x(0) , y(k) ;
		for(int i = 0 ; i < 31 ; i++){
			x[i] = !y[i] ;
		}
		cout << x.to_ulong() << endl ;
	}
	return 0 ;
}

