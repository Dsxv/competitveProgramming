#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		if(n > m){
			int count = 0 ;
			while(n > m){
				if(n&1) {
					count = -1 ;
					break ;
				}
				count++ ;
				n /= 2 ;
			}
			if(count == -1 || (n != m)){
			cout << -1 << '\n' ;
			} else {
			cout << (count + 2) / 3 << '\n' ;
			}
		} else {
			int count = 0 ;
			while(n < m){
				count++ ;
				n *= 2 ;
			}
			if(n != m){
				cout << -1 << '\n' ;
			} else {
				cout << (count + 2) / 3 << '\n' ;
			}
		}
	}
	return 0 ;
}

