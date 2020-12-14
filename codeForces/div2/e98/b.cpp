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
		sort(a , a + n) ;
		int total = accumulate(a , a + n , 0LL) ;
		int mx = 0 ;
		int val = (total + n - 2) / (n - 1) ;

		for(int i = 0 ; i < n - 1 ; i++){
			mx = max(mx , (n - 1) * max(val , a[n-1]) - total) ;
		}
		mx = max(mx , (n - 1) * max(val , a[n - 2]) - total) ;
		cout << mx << '\n' ;
	}
	return 0 ;
}

