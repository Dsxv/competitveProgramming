#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , a , b ;
	cin >> n >> a >> b ;
	n -= a ;
	n = max(0LL , n) ;
	cout << n + b << '\n' ;
	return 0 ;
}

