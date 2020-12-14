#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	while(n % 2 == 0) n /= 2 ;
	while(n % 3 == 0) n /= 3 ;
	while(n % 5 == 0) n /= 5 ;
	cout << (n == 1 ? "Yes" : "No") ;
	return 0 ;
}

