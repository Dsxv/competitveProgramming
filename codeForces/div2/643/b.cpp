#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a,a+n) ;
		int mx = 0 ;
		int count = 0 ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			if(count && count == mx){
				count = 0 ;
				ans++ ;
				mx = 0 ;
			}
			mx = max(mx,a[i]) ;
			count++ ;
		}
		if(count && count == mx) ans++ ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

