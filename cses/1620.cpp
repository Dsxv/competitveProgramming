#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , int* a , int n , int t){
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		ans += (x/a[i]) ;
		if(ans >= t) return 1 ;
	}
	return 0 ;
}
// when doing sum in check, don't check at the end, check as you go to avoid overflow
int32_t main(){
	int n , t;
	cin >> n >> t ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	int lo = 1 , hi  = 1e18 + 10 ;
	int ans = -1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid , a , n , t)) {
			ans = mid ;
			hi = mid - 1 ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

