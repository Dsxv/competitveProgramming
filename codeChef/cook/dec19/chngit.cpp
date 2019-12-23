#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[101] = {0} ;
		for(int i = 0 ; i < n ; i++) {
			int x ; cin >> x ; a[x]++ ;
		}
		cout << n - *max_element(a,a+101) << endl ;
	}
	return 0 ;
}

