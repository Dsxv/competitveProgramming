#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			int s = a[i] + a[j] ;
			ans += (upper_bound(a,a+n,s-1) - (a+j)) - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

