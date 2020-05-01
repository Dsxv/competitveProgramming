#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		int mx = INT_MIN ;
		int d = 0 ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			mx = max(a[i],mx) ;
			d = max(d,mx-a[i]) ;
		}
		int count = 0 ;
		while((1LL<<count) - 1 < d){
			count++ ;
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

