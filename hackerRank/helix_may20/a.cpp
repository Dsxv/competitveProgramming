#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		if(a > b) swap(a,b) ;
		if(b == a){
			cout << 0 << endl ;
		} else if(b%a == 0){
			cout << 1 << endl;
		} else {
			cout << 2 << endl ;
		}
	}
	return 0 ;
}

