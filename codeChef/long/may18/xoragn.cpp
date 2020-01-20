#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int x = 0 ;
		for(int i = 0 ; i < n ; i++){
			int a ;
			cin >> a ;
			x ^= a ;
		}
		cout << 2*x << endl ;
	}
	return 0 ;
}

