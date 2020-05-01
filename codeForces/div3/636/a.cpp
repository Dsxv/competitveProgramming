#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		for(int i = 1 ; i <= 30 ; i++){
			int s = (2LL<<i) - 1 ;
			if(n%s == 0) {
				cout << n/s << '\n';
				break ;
			}
		}
	}
	return 0 ;
}

