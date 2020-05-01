#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int r , g , b ;
	cin >> r >> g >> b ;
	int sum = r + g + b ;
	int mx = max({r,g,b}) ;
	int lo = 0 , hi = 2e9 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(sum >= 3* mid && (sum-mx) >= mid){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

