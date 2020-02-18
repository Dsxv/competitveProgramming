#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >>t ;
	while(t--){
		int n ;
		cin >> n ;
		n *= 2 ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a,a+n) ;
		cout << a[n/2] - a[n/2-1] << endl ;
	}
	return 0 ;
}

