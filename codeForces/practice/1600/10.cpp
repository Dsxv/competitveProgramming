#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a[6] ;
	for(int i = 0 ; i < 6 ; i++){
		cin >> a[i] ;
	}
	int x = a[0] + a[1] + a[2] ;
	x *= x ;
	cout << x - (a[0]*a[0] + a[2]*a[2] + a[4]*a[4]) ;
	return 0 ;
}

