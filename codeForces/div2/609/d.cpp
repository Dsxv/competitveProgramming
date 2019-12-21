#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int b = 0 , w = 0 ;
	// odd with b even with w
	for(int i = 0 ; i < n ; i++){
		if(i&1){
			b += (a[i]+1)/2 ;
			w += a[i]/2 ;
		} else{
			b += a[i]/2 ;
			w += (a[i]+1)/2;
		}
	}
	cout << min(b,w) ;
	return 0 ;
}

