#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int i = 0 ;
		int ans = 0 ;
		while(n / (1LL<<i)){
			ans += n / (1LL<<i) ;
			i++ ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

