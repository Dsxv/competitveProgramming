#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a , b , c , d ;
	cin >> a >> b >> c >> d ;
	while(a > 0 && c > 0){
		c -= b ;
		if(c <= 0) break ;
		a -= d ;
	}
	if(a > 0){
		cout << "Yes" ;
	} else {
		cout << "No" ;
	}
	return 0 ;
}

