#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) a[i] = i + 1 ;
	bitset<1000> b ;
	for(int i = 0 ; i < n ; i++){
		b |= b << a[i] ;
		b[a[i]] = 1 ;
	}
	bool ok = true ;
	for(int i = 1 ; i <= n * (n+1) / 2 ; i++){
		if(!b[i]) ok = false ;
	}
	cout << ok ;
	return 0 ;
}

