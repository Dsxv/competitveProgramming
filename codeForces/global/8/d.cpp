#include <bits/stdc++.h>
using namespace std ;

#define int long long


int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int val[22] = {} ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 22 ; j++){
			if((1LL<<j)&a[i]){
				val[j]++ ;
			}
		}
	}
	int ans = 0 , x = 0 ;
	do{
		x = 0 ;
		for(int i = 0 ; i < 22 ; i++){
			if(val[i]) {
				x += (1LL<<i) ;
				val[i]-- ;
			}
		}
		ans += x*x ;
	} while(x) ;
	cout << ans ;
	return 0 ;
}

