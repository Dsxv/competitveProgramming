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
		int d = 0 ;
		bool ok = true ;
		int ap = -1 , ac = -1 ;
		for(int i = 0 ; i < n ; i++){
			int x,  y ;
			cin >> x >> y ;
			if(x < ap || y < ac) ok = false ;
			ap = x , ac = y ;
			a[i] = x-y ;
			if(a[i] < 0) ok = false ;
		}
		for(int i = 1 ; i < n ; i++){
			if(a[i] < a[i-1]) ok = false ;
		}
		cout << (ok?"YES\n":"NO\n") ;
	}

	return 0 ;
}

