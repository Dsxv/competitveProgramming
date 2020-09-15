#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int sum = accumulate(a,a+n,0LL) ; 
	function<bool(int)> check = [&](int x){
		int cnt = x*(n-1) ;
		for(int i = 0 ; i < n ; i++){
			cnt -= a[i] ;
		}
		return cnt >= 0 ;
	} ;	
	int lo = *max_element(a,a+n) , hi = 1e12 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

