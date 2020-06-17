#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n];
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int ans[n+1] ;
		for(int i = 1 ; i < n ; i++){
			ans[i] = a[i] - a[i-1] ;
		}
		bool val[n] = {} ;
		val[0] = val[n-1] = 1 ;
		bool inc = (ans[1] > 0) ;
		for(int i = 1 ; i < n ; i++){
			if(inc){
				if(ans[i] < 0){
					val[i-1] = 1 ;
					inc = false ;
				}
			} else {
				if(ans[i] > 0){
					val[i-1] = 1 ;
					inc = true ;
				}
			}
		}
		cout << count(val , val+n , 1) << '\n' ;
		for(int i = 0 ; i < n ; i++){
			if(val[i]) cout << a[i] << " " ;
		}
		cout << '\n' ;
	}
	return 0 ;
}

