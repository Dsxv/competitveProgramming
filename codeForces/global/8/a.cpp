#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int a , b , n ;
		cin >> a >> b >> n ;
		int cnt = 0 ;
		if(a < b) swap(a,b) ;
		while(a <= n){
			b += a ;
			swap(a,b) ;
			cnt++ ;
		}
		cout << cnt << '\n' ;
	}
	return 0 ;
}

