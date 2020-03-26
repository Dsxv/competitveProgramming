#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int u , v ;
	cin >> u >> v ;
	if(u > v){
		cout << -1;
		return 0 ;
	}
	if(u == v){
		if(u == 0) {
			cout << 0 ; return 0 ;
		}
		cout << 1 << endl;
		cout << v ; return 0 ;
	}
	v -= u ;
	if(v&1){
		cout << -1 ;
		return 0 ;
	}
	v /= 2 ;
	if((v^u) == (v+u)) cout <<2 << endl <<  v << " " << (v^u) ;
	else cout <<3 << endl << v << " " << v << " " << u ;
	return 0 ;
}

