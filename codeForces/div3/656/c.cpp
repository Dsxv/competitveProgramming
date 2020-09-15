#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		if(n <= 2){
			cout << 0 << '\n';
			continue ;
		}
		int ans = 0 ;
		bool ok = false ;
		for(int i = n - 2 ; i >= 1 ; i--){
			if(a[i] - a[i+1] < 0) ok = true ;
			if(ok && a[i] - a[i-1] < 0) {
				ans = i ;
				break ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

