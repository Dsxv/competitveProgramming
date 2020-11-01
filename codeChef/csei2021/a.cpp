#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[2] = {} ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			a[i%2] += x ;
		}
		cout << max(a[0] , a[1]) << '\n' ;
	}
	return 0 ;
}

