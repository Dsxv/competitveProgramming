#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	if(n&1) {
		cout << 0 ;
		return 0 ;
	} 
	int ans = 0 ;
	n/= 2 ; // to make even n is only even cuz
	while(n){
		ans += (n/5) ;
		n /= 5 ;
	}
	cout << ans ;
	return 0 ;
}

