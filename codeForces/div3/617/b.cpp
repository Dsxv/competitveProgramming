#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int ans = 0 ;
		while(n >= 10) {
			int temp = n%10 ;
			n -= temp ;
			ans += n ;
			n /= 10 ;
			n += temp ;
		}
		ans += n ;
		cout << ans << endl ;
	}
	return 0 ;
}

