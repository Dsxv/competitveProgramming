#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		cout << (abs(b - a) + 9) / 10 << '\n' ;
	}
	return 0 ;
}

