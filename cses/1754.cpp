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
		if(a*2 < b){
			cout << "NO\n" ;
		} else {
			cout << ((a+b) % 3 ? "NO\n" : "YES\n") ;
		}
	}
	return 0 ;
}

