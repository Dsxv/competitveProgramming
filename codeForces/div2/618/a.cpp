#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int x = 0 , ts = 0 , ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			int val ; cin >> val ;
			x += (!val) ;
			ts += val ;
		}
		ans = x ;
		ts += x ;
		if(!ts) ans++ ;
		cout << ans << endl;
	}
	return 0 ;
}

