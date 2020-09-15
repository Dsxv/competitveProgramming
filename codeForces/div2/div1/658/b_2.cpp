#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int id = -1 ;
		for(int i = 0 ; i < n ; i++) if(a[i] > 1) {id = i ; break ;}
		if(~id){
			cout << (id%2?"Second\n":"First\n") ;
		} else {
			cout << (n%2?"First\n":"Second\n") ;
		}
	}
	return 0 ;
}

