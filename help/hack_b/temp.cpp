#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a = 4 , b = 6 , c = 9 ;
	while(a <=b ) {
		while( b <= c){
			while(c > a){
				cout << a << b << c << " " ;
				c-- ;
			}
			b++ ;
		}
		a++ ;
	}
	return 0 ;
}

