#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int x , y ;
		cin >> x >> y ;
		if(x < y) swap(x , y) ;
		cout << x + y + max(0LL , x - y - 1) << '\n' ;
	}
	return 0 ;
}

