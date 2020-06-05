#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	if(k%2){
		if((n*m)%k){
			cout << "NO" ;
			return 0 ;
		} else {
			cout << "YES\n" ;
			int a = n/__gcd(n,k) ;
			int b = m/(k/__gcd(n,k)) ;
			if(a == n){
				b *= 2 ;
			} else {
				a *= 2 ;
			}
			cout << 0 << " " << 0 << endl ;
			cout << a << " " << 0 << endl ;
			cout << 0 << " " << b << endl ;
		}
	} else {
		k /= 2 ;
		if((n*m)%k){
			cout << "NO" ;
			return 0 ;
		} else {
			cout << "YES\n" ;
			int a = n / __gcd(n,k) ;
			int b = m / (k / __gcd(n,k)) ;
			cout << 0 << " " << 0 << endl ;
			cout << a << " " << 0 << endl ;
			cout << 0 << " " << b << endl ;
		}
	}

	return 0 ;
}

