#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , p ;
	cin >> n >> p ;
	int ans = -1 ;
	for(int i = 1 ; i <= 40 ; i++){
		if(n - i*p >= i) {
			if(__builtin_popcount(n-i*p) <= i){
				ans = i ;
				break ;
			}
		}
	}
	cout << ans ;
	return 0 ;
}

