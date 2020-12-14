#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a[k * n] ;
		for(int i = 0 ; i < k * n ; i++) cin >> a[i] ;
		sort( a , a + (k * n)) ;
		int x = n / 2 + 1;
		int ans = 0 ;
		int cur = n*k ;
		for(int i = 0 ; i < k ; i++){
			ans += a[cur - x] ;
			cur -= x ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

