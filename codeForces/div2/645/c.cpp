#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int x1 , y1 , x2 , y2 ;
		cin >> x1 >> y1 >> x2 >> y2 ;
		x2 -= x1 ;
		y2 -= y1 ;
		cout << x2*y2 + 1 << '\n' ;
	}
	return 0 ;
}

