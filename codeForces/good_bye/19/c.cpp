#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int s = 0 , xr = 0 ;
		vector<int> ans ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			s += x ; xr ^= x ;
		}
		s += xr ;
		cout << 2 << '\n' << xr << " " << s << '\n' ;
	}	
	return 0 ;
}

