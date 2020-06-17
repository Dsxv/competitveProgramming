#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}


int32_t main(){
	int n; 
	cin >> n;
	cout << modexp(2,n) ;
	return 0 ;
}

