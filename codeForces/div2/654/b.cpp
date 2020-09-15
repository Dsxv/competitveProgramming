#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , r ;
		cin >> n >> r ;
		if(n > r){
			cout << r*(r+1)/2 << '\n' ;
		} else {
			int x = n - 1 ;
			cout << x*(x+1) / 2 + 1 << '\n' ;
		}
	}
	return 0 ;
}

