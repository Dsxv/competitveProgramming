#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , q ;
	cin >> n >> q ;
	bitset<(int)1e5 + 10> b ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		b |= b << x ;
		b[x] = 1 ;
	}
	int a[(int)1e5 + 10] = {} ;
	a[0] = 0 ;
	for(int i = 1 ; i < 1e5 + 10 ; i++){
		a[i] = a[i-1] + b[i] ;
	}
	while(q--){
		int l ,r ;
		cin >> l >> r ;
		cout << a[r] - a[l-1] << '\n' ;
	}
	return 0 ;
}

