#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int lo = *max_element(a,a+n) ;
	int hi = 1e12 ;
	int sum = accumulate(a,a+n,0LL) ;

	int ans = 0;
	while(lo <= hi){
		int x = (lo + hi) / 2 ;
		if(x*(n-1) >= sum) {
				hi = x - 1 ;
				ans = x ;
		} else {
			lo = x + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

