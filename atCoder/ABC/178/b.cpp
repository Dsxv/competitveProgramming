#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a,  b , c, d ;
	cin >> a >> b >> c >> d ;
	cout << max({a*c , b*d , a*d , b*c}) << '\n' ;
	return 0 ;
}

