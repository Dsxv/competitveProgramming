#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e5 + 10 ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int a[n] ;
	bool neg = false , pos = false ;
	if(n == 1){
		int x ;
		cin >> x ;
		cout << x ;
		return 0 ;
	}
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		if(a[i] < 0) neg = true ;
		else pos = true ;
		a[i] = abs(a[i]) ;
	}
	if(neg && pos){
		cout << accumulate(a, a+n , 0LL) ;
	} else {
		cout << accumulate(a, a+n , 0LL) - 2*(*min_element(a,a+n)) ;
	}
	
	return 0 ;
}

