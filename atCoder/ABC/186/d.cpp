#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort( a , a + n) ;
	int sum = 0 ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans += a[i] * i - sum ;
		sum += a[i] ;
	}
	cout << ans ;
	return 0 ;
}

