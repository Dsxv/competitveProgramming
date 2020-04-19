#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n  , a , b , p , q ;
	cin >> n >> a >> b >> p >> q ;
	int x = (a*b)/__gcd(a,b) ;
	x = n/x ;
	cout << (n/a - x)*p + (n/b - x)*q + max(p,q)*x ;
	return 0 ;
}

