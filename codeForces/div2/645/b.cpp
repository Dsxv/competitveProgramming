#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a,a+n) ;
		int count = 1 ;
		int ans = 1 ;
		for(int i = 0 ; i < n ; i++){
			if(count >= a[i]){
				ans = i + 2 ;
			}
			count++ ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

