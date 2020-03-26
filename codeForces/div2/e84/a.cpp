#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int  n , k ;
		cin >> n >> k ;
		if(n < k*k ){
			cout << "NO\n" ;
		} else {
			if(n%2 == k%2){
				cout << "YES\n" ;
			} else {
				cout << "NO\n" ;
			}
		}
	}
	return 0 ;
}

