#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , l = 0 ;
		cin >> n ;
		while((1LL << l) <= (n&-n)) l++ ;
		int x = (1LL<<l) , ans = 0 ;
		if(x < n) ans = (n - x) / x + 1 ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

