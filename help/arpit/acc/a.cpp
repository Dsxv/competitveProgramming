#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a , b , c,  a1 , b1 , c1 , a2 , b2 , c2 ;
	a1 = 2 , b1 = 45 , c1 = 36 ;
	a2 = 11 , b2 = 26 , c2 = 30 ;
	c = c1 + c2 ;
	b = c / 60 ;
	c = c % 60 ;
	b = b + b1 + b2 ;
	a = b / 60 ;
	b = b % 60 ; 
		a = a + a1 + a2 ;
	cout << a << " " << b << " " << c ;
	return 0 ;
}

