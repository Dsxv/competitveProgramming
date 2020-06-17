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
		int val[n] = {} ;
		val[0] = val[n-1] = 1 ;
		for(int i = 1 ; i < n - 1 ; i++){
			if(a[i] > a[i+1] && a[i] > a[i-1]) val[i] = 1 ;
			if(a[i] < a[i-1] && a[i] < a[i+1]) val[i] = 1 ;
		}
		cout << count(val , val+n , 1) << '\n' ;
		for(int i = 0 ; i < n ; i++) if(val[i]) cout << a[i] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

