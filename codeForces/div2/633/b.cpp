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
		int ans[n] ;
		int count = n - 1 ;
		int l = 0 , r = n - 1 ;
		while(l <= r){
			ans[count--] = a[l++] ;
			if(l <= r) ans[count--] = a[r--] ;
		}
		for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

