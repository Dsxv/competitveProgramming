#include <bits/stdc++.h>
using namespace std ;

#define int long long


int32_t main(){
	int n = 343 , r , s = 0 , m ;
	m = n ;
	while(n){
		r = n % 10 ;
		s = s * 10 + r ;
		n /= 10 ;
	}
	cout << s << " " ;
	if(n != m) cout << m + 1 << endl ;
	else cout << m - 1 << endl ;
	return 0 ;
}

