#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		if(b >= 2*a){
			cout << a << " " << 2*a << '\n' ;
		} else {
			cout << -1 << " " << -1 << '\n' ;
		}
	}
	return 0 ;
}

