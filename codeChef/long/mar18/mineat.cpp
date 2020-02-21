#include <bits/stdc++.h>
using namespace std ;

#define int long long

int check(int x , int* a , int n){
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		count += (a[i] + x - 1) / x ;
	}
	return count ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , h ;
		cin >> n >> h ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int lo = 1 , hi  = 1e9 ;
		int ans = -1 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(check(mid,a,n) <= h) {
				ans = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		assert(ans != -1) ;
		cout << ans << endl ;
	}
	return 0 ;
}

