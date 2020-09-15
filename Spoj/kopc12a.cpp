#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		int a[n] , c[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> c[i] ;
		}
		function<int(int)> check = [&](int x){
			int val = 0 ;
			for(int i = 0 ; i < n ; i++){
				val += abs(a[i]-x)*c[i] ;
			}
			return val ;
		} ;
		int lo = 0 , hi = 10000 ;
		int mn = 1e18 ;
		while((hi - lo) > 3){
			int mid1 = lo + (hi-lo) / 3 ;
			int mid2 = hi - (hi-lo) / 3 ;
			int x1 = check(mid1) , x2 = check(mid2) ;
			if(x1 > x2) lo = mid1 ;
			else hi = mid2 ;
		}
		for(int i = lo ; i <= hi ; i++){
			mn = min(mn , check(i)) ;
		}
		cout << mn << '\n' ;
	}
	return 0 ;
}

