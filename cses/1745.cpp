#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 ;

int32_t main(){
	bitset<N> b(0) ;
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		b |= b << x ;
		b[x] = 1 ; // can't shift 1 << x 
	}
	cout << b.count() << '\n' ;
	for(int i = 1 ; i < N ; i++){
		if(b[i]) cout << i << " " ;
	}
	return 0 ;
}

