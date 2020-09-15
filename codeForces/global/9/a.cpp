#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			x = abs(x) ;
			if(i&1) a[i] = x ;
			else a[i] = -x ;
		}
		for(auto i : a) cout << i << " " ;
		cout << '\n';
	}
	return 0 ;
}

