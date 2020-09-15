#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n; 
		cin >> n; 
		int a[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			a[x-1] = i ;
		}
		int mn = INT_MAX , mx = INT_MIN ;
		for(int i = 0 ; i < n ; i++){
			mx = max(a[i] , mx) ;
			mn = min(a[i] , mn) ;
			if(mx - mn == i) cout << 1 ;
			else cout << 0;
		}
		cout << '\n' ;
	}
	return 0 ;
}

