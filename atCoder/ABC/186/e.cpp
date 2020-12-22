#include <bits/stdc++.h>
using namespace std ;

#define int long long

int gcd(int a , int b , int &x0 , int &y0){
	if(b == 0){
		x0 = 1 ;
		y0 = 0 ;
		return a ;
	}
	int x1 , y1 ;
	int gc = gcd(b , a % b , x1 , y1) ;
	x0 = y1 ;
	y0 = x1 - y1 * (a / b) ;
	return gc ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , s , k ;
		cin >> n >> s >> k ;
		int x0 , y0 ;
		int gc = gcd(k , n , x0 , y0) ;
		if(s % gc){
			cout << -1 << '\n' ;
			continue ;
		}
		x0 = (s / gc) * x0 ;
		y0 = (s / gc) * y0 ;
		x0 *= -1 ;
		int mod = n / gc ;
		x0 = (x0 % mod + mod) % mod ;
		cout << x0 << '\n' ;
	}
	return 0 ;
}

