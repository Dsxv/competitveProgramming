#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	int l = 0 , r = 0 ;
	int ans = 0 ;
	while(r < n){
		while((a[r] - a[l]) > 5) l++ ;
		ans = max(ans , r - l + 1) ;
		r++ ;
	}
	cout << ans ;
	return 0 ;
}

