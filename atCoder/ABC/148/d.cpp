#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	int k = 1 ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++){
		k += k == a[i] ;
	}
	if(k == 1) {
		cout << -1 ;
	}else {
		cout << n - k + 1 ;
	}return 0 ;
}

