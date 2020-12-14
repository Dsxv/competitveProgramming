#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int cnt = 0 ;
		while(n > 1){
			if(n % 2) n-- ;
			else if(n == 2){
				n-- ;
			} else {
				n = 2 ;
			}
			cnt++ ;
		}
		cout << cnt << '\n' ;
	}
	return 0 ;
}

