#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t; 
	cin >> t;
	while(t--){
		int n , l , r;
		cin >> n >> l >> r ;
		int a[n] = {} ;
		a[0] = 0;
		for(int i = 1 ; i < n ; i++){
			a[i] = a[i-1] + (n-i)*2 ;
		}
		bool ok = false ;
		if(r == (n*(n-1) + 1)) {
			ok = true , r-- ;
		}
		for(int i = l ; i <= r ; i++){
			int x = lower_bound(a,a+n,i) - a ;
			if(i&1) cout << x << " " ;
			else cout << x + (i-a[x-1])/2 << " " ;
		}
		if(ok) cout << 1  ;
		cout << '\n' ;
	}
	return 0 ;
}

