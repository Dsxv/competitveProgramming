#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++) cin >> b[i] ;
		if(is_sorted(a,a+n,[](int a , int b) { return a < b ;})){
			cout << "Yes\n" ;
		} else if( count(b,b+n,1) && count(b,b+n,0)){
			cout << "Yes\n" ;
		} else {
			cout << "No\n" ;
		}
	}
	return 0 ;
}

