#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int dpl[n] , dpr[n] ;
	dpr[n-1] = 1 ;
	dpl[0] = 1; 
	for(int i = n-2 ; i >= 0 ; i--){
		if(a[i] < a[i+1]) dpr[i] = dpr[i+1] + 1 ;
		else dpr[i] = 1 ;
	}
	for(int i = 1 ; i < n ; i++) {
		if(a[i] > a[i-1]) dpl[i] = dpl[i-1] + 1 ;
		else dpl[i] = 1 ;
	}
	int ans = max(dpl[n-1],dpr[0]) ;
	for(int i = 1 ; i  < n - 1 ; i++) {
		ans = max({ans,dpl[i],dpr[i]}) ;
		if(a[i+1] > a[i-1]) 
			ans = max(ans,dpl[i-1] + dpr[i+1]) ; 
   }
    cout << ans ;
	return 0 ;
}

