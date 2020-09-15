#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	function<int(int)> check = [&]( int x ){
		bool ok = false ;
		for(int i = 0 ; (i+x-1) < n ; i++){
			ok |= (a[i+x-1] - a[i]) <= 5 ;
		}
		return ok ;
	} ;	
	int lo = 1 , hi = n ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) /  2 ;
		if(check(mid)){
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

