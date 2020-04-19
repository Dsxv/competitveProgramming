#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , q ;
	cin >> n >> q ;
	int mn = INT_MAX ;
	while(q--){
		int l , r ;
		cin >> l >> r ;
		mn = min(mn ,r-l+1) ;
	}
	cout << mn << '\n';
	for(int i = 0 ; i < n ; i++){
		cout << i%mn << " " ;
	}
	return 0 ;
}

