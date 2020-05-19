#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a,  b , c , d ;
		cin >> a >> b >> c >> d ;
		if(a <= b){
			cout << b << '\n' ;
			continue ;
		}
		if(a > b && c <= d){
			cout << -1 << '\n' ;
			continue ;
		}
		int rem = a-b ;
		cout << b + ((rem+c-d-1)/(c-d))*c << '\n';
	}
	return 0 ;
}

