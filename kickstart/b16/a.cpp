#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int l , r ;
	cin >> l >> r ;
	l = min(l,r) ;
	cout << l*(l+1) / 2 << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


