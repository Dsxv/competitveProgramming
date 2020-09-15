#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int x , y , n ;
		cin >> x >> y >> n ;
		int val = (n/x)*x + y;
		if(val > n) val -= x ;
		cout << val << '\n' ;
	}
	return 0 ;
}

