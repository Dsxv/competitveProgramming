#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int x = 6 + 10 + 14;
		if(n <= x){
			cout << "NO\n" ;
		} else {
			int val = n - x ;
			int last = 14 ;
			if(val == 14 || val == 6 || val == 10){
				last = 15 ;
				val-- ;
			}
			cout << "YES\n" ;
			cout << 6 << " " << 10 << " " << last <<  " " << val << '\n' ;
		}
	}
	return 0 ;
}

