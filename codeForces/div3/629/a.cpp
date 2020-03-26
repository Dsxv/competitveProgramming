#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		if(a >= b){
			cout << ceil((double)a/b)*b - a << endl ;
		} else {
			cout << b - a << endl ;
		}
	}
	return 0 ;
}

