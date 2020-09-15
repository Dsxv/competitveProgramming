#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	int lo = 1 , hi = n ;
	int ans = 0 ;
	
	auto check = [&](int x){
		bool ok = false ;
		for(int i = 0 ; i + x - 1 < n ; i++){
			if(a[i+x-1] - a[i] <= 5) ok |= true ;
		}
		return ok ;
	} ; 
	
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid)){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

