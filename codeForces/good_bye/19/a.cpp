#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k1 , k2 ;
		cin >> n >> k1 >> k2 ;
		int a[k1] , b[k2] ;
		for(int i = 0 ; i < k1 ; i++) cin >> a[i] ;
		for(int j = 0 ; j < k2 ; j++) cin >> b[j] ;
		bool ch = *max_element(a,a+k1) > *max_element(b,b+k2) ;
		if(ch) cout << "yes\n" ;
		else cout << "no\n" ;
	}
	return 0 ;
}

