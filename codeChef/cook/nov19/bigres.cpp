#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int h[n] ;
		int x[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> x[i] >> h[i] ;
		}
		sort(x,x+n) ;
		sort(h,h+n) ;
		int ans[n] ;
		int st = 0 , en = n - 1 ;
	return 0 ;
}

